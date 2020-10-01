#ifdef LINE_DIRECTIVE
#line 2 "target_linuxelfx86.h"
#endif

// ---------------------------------------------------------------------------
// addressing modes
enum {
    Target_t_ix,
    Target_t_local,
    Target_t_local_ix,
    Target_t_global,
    Target_t_global_ix,
    Target_t_indirect
};

// ---------------------------------------------------------------------------
enum {
    Target_string_table_size = 1048576        // 1 * 1024*1024
};

int target_string_table_size;
char target_string_table[Target_string_table_size];

// ---------------------------------------------------------------------------
char target_current_label[Str_size];
int target_label_sequence_no;

// ---------------------------------------------------------------------------
enum {
    Target_code_max_size = 33554432  // 32 * 1024*1024
};

int target_code[Target_code_max_size];
int target_code_size;

// ---------------------------------------------------------------------------
enum {
    Target_patch_table_max_size = 8196
};

char target_patch_table_label[2098176];   // Target_patch_table_max_size * Str_size
int target_patch_table_address[Target_patch_table_max_size];
int target_patch_table_size;

// ---------------------------------------------------------------------------

enum {
    Target_elf_header_size = 52,
    Target_elf_program_header_size = 32,
    Target_segment_code_address = 268435456, // 0x10000000  (!positive signed number)
    Target_segment_data_address = 536870912, // 0x20000000
    Target_segment_bss_address = 805306368 // 0x30000000
};

// ---------------------------------------------------------------------------

target_init() {
    copy(target_current_label, "");
    target_label_sequence_no = 0;

    target_string_table_size = 0;
    target_patch_table_size = 0;
    target_code_size = 0;
}

// ---------------------------------------------------------------------------
target_hexchartoint(int c) {
    if (! contains_char("0123456789ABCDEFabcdef", c)) { error_internal(); }

    if      (c <= '9') c = c - '0';
    else if (c <= 'F') c = c - 'A' + 10;
    else               c = c - 'a' + 10;
    
    return c;
}

target_emit8(int val) {
    if (val < 0) { error_internal(); }

    if (target_code_size >= Target_code_max_size) {
        error_target("program code too large");
    }

    val = val - (val / 256) * 256;
    if (val < 0 || val > 256) { error_internal(); }

    target_code[target_code_size] = val;   
    target_code_size = target_code_size + 1;
}

target_emit16(int val) {
    if (val < 0) { error_internal(); }

    target_emit8(val);
    target_emit8(val / 256);
}

target_emit32(int val) {
    int decomplement;

    if (val >= 0) {
        target_emit16(val);
        target_emit16(val/ 65536);
    } else {
        decomplement = val - -(2147483647+1); // bminus supports positive integer constants only, 2147483647=MAX_INT
        target_emit16(decomplement);
        target_emit16(decomplement / 65536 + 32768); // restore msb bit lost when converting to positive
    }
}

target_emit_hex(char hex_str[]) {
    int pos;

    pos = 0;
    while (pos + 2 <= length(hex_str)) {
        target_emit8(target_hexchartoint(hex_str[pos]) * 16 + target_hexchartoint(hex_str[pos + 1]));
        pos = pos + 2;
        if (hex_str[pos] == ' ') {
            pos = pos + 1;
        }
    }
    if (hex_str[pos] != 0) { error_internal(); }
}

target_emit_inst(char hex_str[], int address) {
    target_emit_hex(hex_str);
    target_emit32(address);
}

target_emit_patch32(int patch_address, int val) {
    int save_target_code_size;

    save_target_code_size = target_code_size;
    target_code_size = patch_address; 

    target_emit32(val);
    target_code_size = save_target_code_size;
}

// ---------------------------------------------------------------------------
target_emit_rel_jump32(char hex_str[], char label[], char label_postfix[]) {
    char patch_label[Str_size];

    if (target_patch_table_size >= Target_patch_table_max_size) {
        error_target("out of elf patch table space");
    }

    copy(patch_label, label);
    append(patch_label, label_postfix);

    target_emit_hex(hex_str);
    target_emit32(0);

    target_patch_table_address[target_patch_table_size] = target_code_size - 4;
    copy_to(target_patch_table_label, patch_label, target_patch_table_size * Str_size);
    target_patch_table_size = target_patch_table_size + 1;
}

target_emit_label(char label[], char label_postfix[]) {
    char address_label[Str_size];

    if (target_patch_table_size >= Target_patch_table_max_size) {
        error_target("out of elf patch table space");
    }

    copy(address_label, label);
    append(address_label, label_postfix);

    target_patch_table_address[target_patch_table_size] = -target_code_size;
    copy_to(target_patch_table_label, address_label, target_patch_table_size * Str_size);
    target_patch_table_size = target_patch_table_size + 1;
}

// ---------------------------------------------------------------------------
target_patch_jumps_with_label(char label[], int address) {
    int i;
    int patch_address;
    char patch_address_label[Str_size];

    // loop through all the jump labels, if a match is found, calculate rel address and patch
    i = 0;
    while (i < target_patch_table_size) {
        patch_address = target_patch_table_address[i];
        if (patch_address > 0) {
            copy_from(patch_address_label, target_patch_table_label, i * Str_size);           
            if (str_equals(label, patch_address_label)) {
                target_emit_patch32(patch_address, address - patch_address - 4); // PC is pointing to next inst
            }
        }
        i = i + 1;
    }
}

target_patch_jumps() {
    int i;
    int address;
    char address_label[Str_size];

    // loop through all the address labels (labels on the left)
    // (address labels are stored negated)
    i = 0;
    while (i < target_patch_table_size) {
        address = -target_patch_table_address[i];
        if (address > 0) {
            copy_from(address_label, target_patch_table_label, i * Str_size);
            target_patch_jumps_with_label(address_label, address);
        }
        i = i + 1;
    }
}

target_patch_program_header(int header_no, int offset_in_file, int size_in_file, int size_in_memory)
{
    target_emit_patch32(Target_elf_header_size + header_no * Target_elf_program_header_size + 4, offset_in_file);
    target_emit_patch32(Target_elf_header_size + header_no * Target_elf_program_header_size + 16, size_in_file);
    target_emit_patch32(Target_elf_header_size + header_no * Target_elf_program_header_size + 20, size_in_memory);
}

// ---------------------------------------------------------------------------

target_op_branch(char label[], char postfix[]) {
    target_emit_rel_jump32("e9", label, postfix);
}

target_op_branch_back(char label[], char postfix[]) {
    target_emit_rel_jump32("e9", label, postfix);
}

target_op_branch_if_less(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 8f", label, postfix);
}

target_op_branch_if_greater(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 8c", label, postfix);
}

target_op_branch_if_equals(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 84", label, postfix);
}

target_op_branch_if_not_equals(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 85", label, postfix);
}

target_op_branch_if_true(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 85", label, postfix);
}

target_op_branch_if_false(char label[], char postfix[]) {
    target_emit_rel_jump32("0f 84", label, postfix);
}

// ---------------------------------------------------------------------------
target_op_loadx() {
    target_emit_hex("89 c3"); // movl %eax, %ebx
}

target_op_load_constant(int constant) {
    target_emit_inst("b8", constant); // movl $constant, %eax
}

target_op_load_address(int address, int address_mode_type) {
    if (address_mode_type == Target_t_ix) {
        target_emit_inst("8d 04 9d", address); // lea address(,%ebx,4),%eax

    } else if (address_mode_type == Target_t_local) {
        target_emit_inst("8d 85", address); // lea address(%ebp),%eax

    } else if (address_mode_type == Target_t_global) {
        target_emit_inst("8d 05", address); // lea address,%eax

    } else { error_internal(); }
}

target_op_load(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_inst("8b 85", address); // movl address(%ebp), %eax

    } else if (address_mode_type == Target_t_local_ix) {
        target_emit_inst("8b 84 9d", address); // movl address(%ebp,%ebx,4),%eax

    } else if (address_mode_type == Target_t_global) {
        target_emit_inst("a1", address); // movl address ,%eax

    } else if (address_mode_type == Target_t_global_ix) {
        target_emit_inst("8b 04 9d", address); // movl address(,%ebx,4),%eax

    } else if (address_mode_type == Target_t_indirect) {
        target_emit_hex("8b 03"); // movl (%ebx), %eax

    } else { error_internal(); }
}

target_op_store(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_inst("89 85", address); // movl %eax,address(%ebp)

    } else if (address_mode_type == Target_t_local_ix) {
        target_emit_inst("89 84 9d", address); // movl %eax,address(%ebp,%ebx,4)

    } else if (address_mode_type == Target_t_global) {
        target_emit_inst("a3", address); // movl %eax,address

    } else if (address_mode_type == Target_t_global_ix) {
        target_emit_inst("89 04 9d", address); // movl %eax, address(,%ebx,4)

    } else if (address_mode_type == Target_t_indirect) {
        target_emit_hex("89 03"); // movl %eax,(%ebx)

    } else { error_internal(); }
}

target_op_add(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_inst("03 85", address); // addl address(%ebp),%eax

    } else { error_internal(); }
}

target_op_subtract(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_inst("2b 85", address); // subl address(%ebp),%eax

    } else { error_internal(); }
}

target_op_multiply(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_inst("f7 ad", address); // imull address(%ebp)

    } else { error_internal(); }
}

target_op_divide(int address, int address_mode_type) {
    if (address_mode_type == Target_t_local) {
        target_emit_hex("99"); // cdq
        target_emit_inst("f7 bd", address); // idivl address(%ebp)

    } else { error_internal(); }
}

target_op_test() {
    target_emit_hex("83 f8 00"); // cmpl $0x0, %eax
}

// ---------------------------------------------------------------------------
target_op_subroutine_begin(char function_name[], int argument_count, int local_frame_size) {
    if (local_frame_size >= 8192) {
        error_target("Local storage on stack frame is limited to 32kb on x86 target");
    }

    target_emit_label(function_name, "");
    target_emit_hex("c8"); target_emit16(local_frame_size * 4); target_emit8(0); // enter $local_frame_size,$0
}

target_op_subroutine_end(char function_name[], int argument_count, int local_frame_size) {

    target_emit_hex("c9"); // leave
    target_emit_hex("c3"); // ret
}

target_op_call_subroutine(char function_name[], int argument_count, int local_frame_size) {
    if (argument_count >= 32) {
        error_target("Functions arguments are limited to 31 on x86 target");
    }

    target_emit_rel_jump32("e8", function_name, ""); // call function_name

    if (argument_count < 1) {
        return;
    }

    target_emit_hex("83 c4"); target_emit8(argument_count * 4); // addl $argument_count*4,%esp
}

target_op_pass_argument(int argument_no, int argument_count, int local_frame_size) {
    target_emit_hex("50"); // pushl %eax
}

// ---------------------------------------------------------------------------
target_begin_branch_block(char label[], char label_postfix[]) {
}

target_end_branch_block(char label[], char label_postfix[]) {
    target_emit_label(label, label_postfix);
}

target_begin_back_branch_block(char label[], char label_postfix[]) {
    target_emit_label(label, label_postfix);
}

target_end_back_branch_block(char label[], char label_postfix[]) {
}

// ---------------------------------------------------------------------------
target_built_in_function_debug() {
    char label[Str_size];

    target_emit_hex("89 c1");                                  // mov    %eax,%ecx

    target_get_label("debug_neg_if", label);
    target_emit_hex("83 f8 00");                               // cmp    $0x0,%eax
    target_emit_rel_jump32("0f 8d", label, "_end");            // jge    debug_neg_if_end
    target_emit_hex("f7 d8");                                  // neg    %eax
    target_emit_label(label, "_end");

    target_emit_hex("6a 0a");                                  // push   $0xa
 
    target_get_label("debug_to_str", label);
    target_emit_hex("be 01 00 00 00");                         // mov    $0x1,%esi
    target_emit_label(label, "_begin");
    target_emit_hex("ba 00 00 00 00");                         // mov    $0x0,%edx
    target_emit_hex("bb 0a 00 00 00");                         // mov    $0xa,%ebx
    target_emit_hex("f7 f3");                                  // div    %ebx
    target_emit_hex("83 c2 30");                               // add    $0x30,%edx
    target_emit_hex("52");                                     // push   %edx
    target_emit_hex("46");                                     // inc    %esi
    target_emit_hex("83 f8 00");                               // cmp    $0x0,%eax
    target_emit_rel_jump32("0f 84", label, "_end");            // je     debug_to_str_end
    target_emit_rel_jump32("e9", label, "_begin");             // jmp    debug_to_str_begin
    target_emit_label(label, "_end");

    target_get_label("debug_sign_if", label);
    target_emit_hex("83 f9 00");                               // cmp    $0x0,%ecx
    target_emit_rel_jump32("0f 8d", label, "_end");            // jge    debug_sign_if_end
    target_emit_hex("6a 2d");                                  // push   $0x2d
    target_emit_hex("46");                                     // inc    %esi
    target_emit_label(label, "_end");

    target_get_label("debug_print", label);
    target_emit_label(label, "_begin");
    target_emit_hex("83 fe 00");                               // cmp    $0x0,%esi
    target_emit_rel_jump32("0f 84", label, "_end");            // je     debug_print_end
    target_emit_hex("4e");                                     // dec    %esi
    target_emit_hex("b8 04 00 00 00");                         // mov    $0x4,%eax
    target_emit_hex("89 e1");                                  // mov    %esp,%ecx
    target_emit_hex("bb 01 00 00 00");                         // mov    $0x1,%ebx
    target_emit_hex("ba 01 00 00 00");                         // mov    $0x1,%edx
    target_emit_hex("cd 80");                                  // int    $0x80
    target_emit_hex("83 c4 04");                               // add    $0x4,%esp
    target_emit_rel_jump32("e9", label, "_begin");             // jmp    debug_print_begin
    target_emit_label(label, "_end");

}

target_built_in_function_exit() {
    target_emit_hex("89 c3");                                  // mov    %eax,%ebx
    target_emit_hex("b8 01 00 00 00");                         // mov    $0x1,%eax
    target_emit_hex("cd 80");                                  // int    $0x80
}

target_built_in_function_fgetc() {
    char label[Str_size];

    target_get_label("fgetc_if", label);
    target_emit_hex("83 ec 04");                               // sub    $0x4,%esp
    target_emit_hex("b8 03 00 00 00");                         // mov    $0x3,%eax
    target_emit_hex("bb 00 00 00 00");                         // mov    $0x0,%ebx
    target_emit_hex("89 e1");                                  // mov    %esp,%ecx
    target_emit_hex("ba 01 00 00 00");                         // mov    $0x1,%edx
    target_emit_hex("cd 80");                                  // int    $0x80
    target_emit_hex("83 f8 01");                               // cmp    $0x1,%eax
    target_emit_rel_jump32("0f 85", label, "_else");           // jne    fgetc_if_else
    target_emit_hex("58");                                     // pop    %eax
    target_emit_hex("25 ff 00 00 00");                         // and    $0xff,%eax
    target_emit_rel_jump32("e9", label, "_end");               // jmp    fgetc_if_end
    target_emit_label(label, "_else");
    target_emit_hex("83 c4 04");                               // add    $0x4,%esp
    target_emit_hex("b8 ff ff ff ff");                         // mov    $0xffffffff,%eax
    target_emit_label(label, "_end");
}

target_built_in_function_fputc_stdout() {
    target_emit_hex("50");                                     // push   %eax
    target_emit_hex("b8 04 00 00 00");                         // mov    $0x4,%eax
    target_emit_hex("bb 01 00 00 00");                         // mov    $0x1,%ebx
    target_emit_hex("89 e1");                                  // mov    %esp,%ecx
    target_emit_hex("ba 01 00 00 00");                         // mov    $0x1,%edx
    target_emit_hex("cd 80");                                  // int    $0x80
    target_emit_hex("83 c4 04");                               // add    $0x4,%esp
}

target_built_in_function_fputc_stderr() {
    target_emit_hex("50");                                     // push   %eax
    target_emit_hex("b8 04 00 00 00");                         // mov    $0x4,%eax
    target_emit_hex("bb 02 00 00 00");                         // mov    $0x2,%ebx
    target_emit_hex("89 e1");                                  // mov    %esp,%ecx
    target_emit_hex("ba 01 00 00 00");                         // mov    $0x1,%edx
    target_emit_hex("cd 80");                                  // int    $0x80
    target_emit_hex("83 c4 04");                               // add    $0x4,%esp
}

// ---------------------------------------------------------------------------
target_allocate_string(char string[], int string_length) {
    int i;
    int offset;

    if (target_string_table_size + string_length > Target_string_table_size) {
        error_target("out of initialised (string) storage space");
    }

    i = 0;
    while(i <= string_length) {
        target_string_table[target_string_table_size + i] = string[i];
        i = i + 1;
    }

    offset = target_string_table_size;
    target_string_table_size = target_string_table_size + string_length;

    return Target_segment_data_address + offset * 4; // 4 bytes per char
}

target_allocate_global_address(int offset, int var_size) {
    
    return Target_segment_bss_address + offset * 4; // 4 bytes per int
}

target_allocate_local_address(int offset, int var_size, int function_argument_count) {

    return -offset * 4 - var_size * 4;
}

target_allocate_function_argument_address(int argument_no, int var_size) {

    return argument_no * 4 + 4;
}

target_get_label(char start_with[], char out_label[]) {
    char sequence_no_str[Str_size];

    int_to_str(target_label_sequence_no, sequence_no_str);
    copy(out_label, start_with);
    append(out_label, "_");
    append(out_label, sequence_no_str);

    target_label_sequence_no = target_label_sequence_no + 1;
}

target_comment_print(char source_code_text[]) {
}

// ---------------------------------------------------------------------------
target_program_begin() {

    // elf header
    // loaded with the code segment, execution begins at the end of the elf header
    target_emit8(127); // e_ident 0x7F "ELF"
    target_emit8('E');
    target_emit8('L');
    target_emit8('F');
    target_emit8(1); // e_ident EI_CLASS=ELFCLASS32 - 32 bit
    target_emit8(1); // e_ident EI_DATA=1 - little endian
    target_emit8(1); // e_ident EI_VERSION=1
    target_emit8(0); // e_ident pad
    target_emit32(0);       
    target_emit32(0);
    target_emit16(2); // e_type=2 - executable
    target_emit16(3); // e_machine=3 - 32 bit x86
    target_emit32(1); // e_version=1
    target_emit32(Target_segment_code_address + Target_elf_header_size + (3 * Target_elf_program_header_size)); // e_entry - execution address, code is loaded into memory with the elf header and program headers
    target_emit32(Target_elf_header_size); // e_phoff - program header table offset in elf, right after elf header
    target_emit32(0);  // e_shoff - section header table offset in elf
    target_emit32(0);  // e_flags
    target_emit16(Target_elf_header_size); // e_hsize - elf header size
    target_emit16(Target_elf_program_header_size); // e_phentsize - program header size
    target_emit16(3);  // e_phnum - no of program headers = 3, text + data + bss
    target_emit16(0);  // e_shentsize - section header size, no section headers
    target_emit16(0);  // e_shnum - no of section headers
    target_emit16(0);  // e_shstrndx - section name index
    if (target_code_size != Target_elf_header_size) error_internal();

    // elf program header - text (code)
    // patch p_filesz, p_memsz
    target_emit32(1); // p_type PT_LOAD
    target_emit32(0); // p_offset - offset in file, load code with elf header to align with page size
    target_emit32(Target_segment_code_address); // p_vaddr - virtual address for segment
    target_emit32(Target_segment_code_address); // p_paddr - same as p_vaddr, ignored ??
    target_emit32(0); // p_filesz - segment size in file
    target_emit32(0); // p_memsz - segment size in memory
    target_emit32(5); // p_flags - rwx flags, PF_R(4) | PF_X(1), 1+4=5
    target_emit32(0); // p_align - segment will be aligned on a 4K boundary, both in memory and in file

    // elf program header - data, initialised data
    // patch p_offset, p_filesz, p_memsz
    target_emit32(1);  // p_type PT_LOAD
    target_emit32(0);  // p_offset - offset in file, file will be padded so segment starts on 4K boundary in file
    target_emit32(Target_segment_data_address); // p_vaddr - virtual address for segment
    target_emit32(Target_segment_data_address); // p_paddr - same as p_vaddr, ignored ??
    target_emit32(0); // p_filesz - segment size in file
    target_emit32(0); // p_memsz - segment size in memory
    target_emit32(6); // p_flags - rwx flags, PF_R(4) | PF_W(2) 2+4=6
    target_emit32(0); // p_align - segment will be aligned on a 4K boundary, both in memory and in file

    // elf program header - bss, uninitialised data
    // patch p_memsz
    target_emit32(1); // p_type PT_LOAD
    target_emit32(0); // p_offset - offset in file, ignore
    target_emit32(Target_segment_bss_address); // p_vaddr - virtual address for segment
    target_emit32(Target_segment_bss_address); // p_paddr - same as p_vaddr, ignored ??
    target_emit32(0); // p_filesz - segment size in file is 0
    target_emit32(0); // p_memsz - segment size in memory
    target_emit32(6); // p_flags - rwx flags, PF_R(4) | PF_W(2) 2+4=6
    target_emit32(0); // p_align - segment will be aligned on a 4K boundary, both in memory and in file

    // start of execution, e_entry in elf header points here
    target_emit_rel_jump32("e8", "main", "");                    // call main
    target_emit_hex("b8 01 00 00 00");                         // mov    $0x1,%eax
    target_emit_hex("bb 00 00 00 00");                         // mov    $0x0,%ebx
    target_emit_hex("cd 80");                                  // int    $0x80
}
 
target_program_end(int global_data_size) {
    int i;
    int code_page_size;

    // patch relative jumps in code
    target_patch_jumps();

    // pad code segment to memory page boundary
    code_page_size = (target_code_size - 1) / 4096 * 4096 + 4096;

    // patch elf program headers, code, data, and bss
    target_patch_program_header(0, 0, target_code_size, target_code_size);
    target_patch_program_header(1, code_page_size, target_string_table_size * 4, target_string_table_size * 4);
    target_patch_program_header(2, 0, 0, global_data_size * 4);

    // write elf header and code segment
    i = 0;
    while (i < code_page_size) {
        if (i < target_code_size) {
            fputc(target_code[i], stdout);
        } else {
            fputc(0, stdout);
        }
        i = i + 1;
    }

    // write data segment (strings)
    i = 0;
    while (i < target_string_table_size) {
        target_code_size = 0;
        target_emit32(target_string_table[i]);

        fputc(target_code[0], stdout);
        fputc(target_code[1], stdout);
        fputc(target_code[2], stdout);
        fputc(target_code[3], stdout);
        i = i + 1;
    }
}
