#ifndef _MSC_VER
#line 2 "target_linuxassemblerx86.h"
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
    Target_string_table_size = 1048576        // 1 * 1024 * 1024
};

int target_string_table_length;
char target_string_table[Target_string_table_size];

// ---------------------------------------------------------------------------
char target_current_label[Str_size];

int target_label_sequence_no;

// ---------------------------------------------------------------------------
target_init() {

    target_string_table_length = 0;
    copy(target_current_label, "");
    target_label_sequence_no = 0;
}


// ---------------------------------------------------------------------------
target_comment_print(char comment_block[]) {
    int i;
    char line[Str_size];

    i = 0;
    copy(line, "");

    while (comment_block[i] != 0) {

        if (str_equals(line, "")) {
            fill_until_col(line, 60);
            append(line, "# ");
        }

        if (comment_block[i] != '\n') {
            append_char(line, comment_block[i]);
        }

        if (comment_block[i] == '\n' || comment_block[i + 1] == 0) {
            writeln(line);
            copy(line, "");
        }

        i = i + 1;
    }
}

// ---------------------------------------------------------------------------
target_instruction_print(char opcode[], char operand1[], char operand2[]) {
    char line[Str_size];

    copy(line, "");

    if (! str_equals(target_current_label, "")) {
        copy(line, target_current_label);
        append(line, ":");

        copy(target_current_label, "");
    }

    append(line, " ");
    fill_until_col(line, 24);

    append(line, opcode);

    if (str_equals(operand1, "")) {
        writeln(line);
        return;
    }

    append(line, " ");
    fill_until_col(line, 42);
    append(line, operand1);

    if (str_equals(operand2, "")) {
        writeln(line);
        return;
    }

    append(line, ", ");
    append(line, operand2);
    writeln(line);
}
// ---------------------------------------------------------------------------
target_instruction_no_operand(char opcode[]) {
    
    target_instruction_print(opcode, "", "");
}

target_instruction_one_operand(char opcode[], char operand1[]) {

    target_instruction_print(opcode, operand1, "");
}

target_instruction_two_operands(char opcode[], char operand1[], char operand2[]) {

    target_instruction_print(opcode, operand1, operand2);
}

target_instruction_branch(char opcode[], char label[], char label_postfix[]) {
    char location_field[Str_size];

    copy(location_field, label);
    append(location_field, label_postfix);

    target_instruction_one_operand(opcode, location_field);
}

// ---------------------------------------------------------------------------
generate_address(char address_out[], int address, int address_mode) {

    if (address_mode == Target_t_global || address_mode == Target_t_global_ix) {
        if (address <= 0) {
            int_to_str(-address, address_out);
            append(address_out, "+global");
        } else {
            int_to_str(address, address_out);
            append(address_out, "+string");
        }

        if (address_mode == Target_t_global_ix) {
            append(address_out, "(,%ebx,4)");
        }

    } else if (address_mode == Target_t_local) {
        int_to_str(address, address_out);
        append(address_out, "(%ebp)");

    } else if (address_mode == Target_t_local_ix) {
        int_to_str(address, address_out);
        append(address_out, "(%ebp,%ebx,4)");

    } else if (address_mode == Target_t_ix) {
        copy(address_out, "(,%ebx,4)");

    } else if (address_mode == Target_t_indirect) {
        copy(address_out, "(%ebx)");

    } else {
        error_internal();
    }
}

// ---------------------------------------------------------------------------
target_op_branch(char label[], char postfix[]) {
    target_instruction_branch("jmp", label, postfix);
}

target_op_branch_back(char label[], char postfix[]) {
    target_instruction_branch("jmp", label, postfix);
}

target_op_branch_if_less(char label[], char postfix[]) {
    target_instruction_branch("jg", label, postfix);
}

target_op_branch_if_greater(char label[], char postfix[]) {
    target_instruction_branch("jl", label, postfix);
}

target_op_branch_if_equals(char label[], char postfix[]) {
    target_instruction_branch("je", label, postfix);
}

target_op_branch_if_not_equals(char label[], char postfix[]) {
    target_instruction_branch("jne", label, postfix);
}

target_op_branch_if_true(char label[], char postfix[]) {
    target_instruction_branch("jnz", label, postfix);
}

target_op_branch_if_false(char label[], char postfix[]) {
    target_instruction_branch("jz", label, postfix);

}

// ---------------------------------------------------------------------------
target_op_loadx() {
    target_instruction_two_operands("movl", "%eax", "%ebx");
}

target_op_load_constant(int constant) {
    char constant_str[Str_size];
    char constant_field[Str_size];

    int_to_str(constant, constant_str);
    copy(constant_field, "$");
    append(constant_field, constant_str);

    target_instruction_two_operands("movl", constant_field, "%eax");
}

target_op_load_address(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_two_operands("lea", address_str, "%eax");
}

target_op_load(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_two_operands("movl", address_str, "%eax");
}

target_op_store(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_two_operands("movl", "%eax", address_str);
}

target_op_add(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_two_operands("addl", address_str, "%eax");
}

target_op_subtract(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_two_operands("subl", address_str, "%eax");
}

target_op_multiply (int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_one_operand("imull", address_str);
}

target_op_divide(int address, int address_mode_type) {
    char address_str[Str_size];

    generate_address(address_str, address, address_mode_type);
    target_instruction_no_operand("cdq");
    target_instruction_one_operand("idivl", address_str);
}

target_op_test() {
    target_instruction_two_operands("cmpl", "$0", "%eax");
}

// ---------------------------------------------------------------------------
target_op_subroutine_begin(char function_name[], int argument_count, int local_frame_size) {
    char local_frame_size_str[Str_size];
    char local_frame_size_field[Str_size];

    target_emit_label(function_name, "");

    int_to_str(local_frame_size * 4, local_frame_size_str);
    copy(local_frame_size_field, "$");
    append(local_frame_size_field, local_frame_size_str);
    target_instruction_two_operands("enter", local_frame_size_field, "$0");
}

target_op_subroutine_end(char function_name[], int argument_count, int local_frame_size) {

    target_emit_label("", "");
    target_instruction_no_operand("leave");
    target_instruction_no_operand("ret");
}

target_op_call_subroutine(char function_name[], int argument_count, int local_frame_size) {
    char argument_size_str[Str_size];
    char argument_size_field[Str_size];

    target_instruction_one_operand("call", function_name);

    if (argument_count < 1) {
        return;
    }

    int_to_str(argument_count * 4, argument_size_str);
    copy(argument_size_field, "$");
    append(argument_size_field, argument_size_str);

    target_instruction_two_operands("addl", argument_size_field, "%esp");
}

target_op_pass_argument(int argument_no, int argument_count, int local_frame_size) {

    target_instruction_one_operand("pushl", "%eax");
}

// ---------------------------------------------------------------------------
target_emit_label(char label[], char label_postfix[]) {

    if (! str_equals(target_current_label, "")) {
        write(target_current_label);
        writeln(":");
    }

    copy(target_current_label, label);
    append(target_current_label, label_postfix);
}

// ---------------------------------------------------------------------------
target_begin_branch_block(char label[], char label_postfix[]) {
}

// ---------------------------------------------------------------------------
target_end_branch_block(char label[], char label_postfix[]) {
    target_emit_label(label, label_postfix);
}

// ---------------------------------------------------------------------------
target_begin_back_branch_block(char label[], char label_postfix[]) {
    target_emit_label(label, label_postfix);
}

// ---------------------------------------------------------------------------
target_end_back_branch_block(char label[], char label_postfix[]) {
}

// ---------------------------------------------------------------------------
target_built_in_function_debug() {
    char label[Str_size];

    target_instruction_two_operands("movl", "%eax", "%ecx");

    target_get_label("debug_neg_if", label);
    target_instruction_two_operands("cmpl", "$0", "%eax");
    target_instruction_branch("jge", label, "_end");
    target_instruction_one_operand("neg", "%eax");
    target_emit_label(label, "_end");

    target_instruction_one_operand("pushl", "$'\\n");

    target_get_label("debug_to_str", label);
    target_instruction_two_operands("movl", "$1", "%esi");
    target_emit_label(label, "_begin");
    target_instruction_two_operands("movl", "$0", "%edx");
    target_instruction_two_operands("movl", "$10", "%ebx");
    target_instruction_one_operand("divl", "%ebx");
    target_instruction_two_operands("addl", "$48", "%edx");
    target_instruction_one_operand("pushl", "%edx");
    target_instruction_one_operand("incl", "%esi");
    target_instruction_two_operands("cmpl", "$0", "%eax");
    target_instruction_branch("jz", label, "_end");
    target_instruction_branch("jmp", label, "_begin");
    target_emit_label(label, "_end");

    target_get_label("debug_sign_if", label);
    target_instruction_two_operands("cmpl", "$0", "%ecx");
    target_instruction_branch("jge", label, "_end");
    target_instruction_one_operand("pushl", "$'-");
    target_instruction_one_operand("incl", "%esi");
    target_emit_label(label, "_end");
    
    target_get_label("debug_print", label);
    target_emit_label(label, "_begin");
    target_instruction_two_operands("cmpl", "$0", "%esi");
    target_instruction_branch("jz", label, "_end");
    target_instruction_one_operand("decl", "%esi");
    target_instruction_two_operands("movl", "$4", "%eax");
    target_instruction_two_operands("movl", "%esp", "%ecx");
    target_instruction_two_operands("movl", "$1", "%ebx");
    target_instruction_two_operands("movl", "$1", "%edx");
    target_instruction_one_operand("int", "$0x80");
    target_instruction_two_operands("addl", "$4", "%esp");
    target_instruction_branch("jmp", label, "_begin");
    target_emit_label(label, "_end");
}

target_built_in_function_exit() {

    target_instruction_two_operands("movl", "%eax", "%ebx");
    target_instruction_two_operands("movl", "$1", "%eax");
    target_instruction_one_operand("int", "$0x80");
}

target_built_in_function_fgetc() {
    char label[Str_size];

    target_get_label("fgetc_if", label);
    target_instruction_two_operands("subl", "$4", "%esp");
    target_instruction_two_operands("movl", "$3", "%eax");
    target_instruction_two_operands("movl", "$0", "%ebx");
    target_instruction_two_operands("movl", "%esp", "%ecx");
    target_instruction_two_operands("movl", "$1", "%edx");
    target_instruction_one_operand("int", "$0x80");
    target_instruction_two_operands("cmpl", "$1", "%eax");
    target_instruction_branch("jne", label, "_else");
    target_instruction_one_operand("popl", "%eax");
    target_instruction_two_operands("andl", "$0xff", "%eax");
    target_instruction_branch("jmp", label, "_end");
    target_emit_label(label, "_else");
    target_instruction_two_operands("addl", "$4", "%esp");
    target_instruction_two_operands("movl", "$-1", "%eax");
    target_emit_label(label, "_end");
}

target_built_in_function_fputc_stdout() {
    target_instruction_one_operand("pushl", "%eax");
    target_instruction_two_operands("movl", "$4", "%eax");
    target_instruction_two_operands("movl", "$1", "%ebx");
    target_instruction_two_operands("movl", "%esp", "%ecx");
    target_instruction_two_operands("movl", "$1", "%edx");
    target_instruction_one_operand("int", "$0x80");
    target_instruction_two_operands("addl", "$4", "%esp");
}

target_built_in_function_fputc_stderr() {
    target_instruction_one_operand("pushl", "%eax");
    target_instruction_two_operands("movl", "$4", "%eax");
    target_instruction_two_operands("movl", "$2", "%ebx");
    target_instruction_two_operands("movl", "%esp", "%ecx");
    target_instruction_two_operands("movl", "$1", "%edx");
    target_instruction_one_operand("int", "$0x80");
    target_instruction_two_operands("addl", "$4", "%esp");
}


// ---------------------------------------------------------------------------
target_allocate_string(char string[], int string_length) {
    int i;
    int offset;

    if (target_string_table_length + string_length > Target_string_table_size) {
        error_target("out of initialised (string) storage space");
    }

    i = 0;
    while(i <= string_length) {
        target_string_table[target_string_table_length + i] = string[i];
        i = i + 1;
    }

    offset = target_string_table_length;
    target_string_table_length = target_string_table_length + string_length;

    return offset * 4 + 4;
}

target_allocate_global_address(int offset, int var_size) {
    
    return -offset * 4;
}

target_allocate_local_address(int offset, int var_size, int function_argument_count) {

    return -offset * 4 - var_size * 4;
}

target_allocate_function_argument_address(int argument_no, int var_size) {

    return argument_no * 4 + 4;
}
// ---------------------------------------------------------------------------
target_program_begin() {

    writeln("");
    writeln(".text");
    writeln(".globl _start");
    writeln("_start:");
    target_instruction_one_operand("call", "main");
    target_instruction_two_operands("movl", "$1", "%eax");
    target_instruction_two_operands("movl", "$0", "%ebx");
    target_instruction_one_operand("int", "$0x80");
    writeln("");
}
 
target_program_end(int global_data_size) {
    int i;
    int ch;
    char s[Str_size];
    char global_data_size_str[Str_size];

    int_to_str(global_data_size * 4, global_data_size_str);

    writeln(".bss");
    writeln("global:");
    write(".lcomm global_storage_space, ");
    writeln(global_data_size_str);
    writeln("");
    writeln(".data");
    writeln("string:");
    writeln(".int 0");
    i = 0;
    while (i < target_string_table_length) {
        ch = target_string_table[i];

        int_to_str(ch, s);
        write(".int ");
        write(s);

        if (ch >= ' ' && ch <= '~') {
            copy(s, " # ' '");
            s[4] = ch;
            write(s);
        }
 
        writeln("");
        i = i + 1;
    }

    writeln(".end");
}


// ---------------------------------------------------------------------------
target_get_label(char start_with[], char out_label[]) {
    char sequence_no_str[Str_size];

    int_to_str(target_label_sequence_no, sequence_no_str);
    copy(out_label, start_with);
    append(out_label, "_");
    append(out_label, sequence_no_str);

    target_label_sequence_no = target_label_sequence_no + 1;
}
