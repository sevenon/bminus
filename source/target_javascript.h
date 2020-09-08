#ifndef _MSC_VER
#line 2 "target_javascript.h"
#endif

// memory layout
// the size local storage area (stack frames) is fixed
// the size of the string table and global storage is allocated by the compiler
// ---------------------------------------------------------------------------
// | string table ------> | local storage -------> | <------- global storage |
// ---------------------------------------------------------------------------
enum {
    Target_local_storage_size = 1048576        // 1 * 1024 * 1024
};

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

int target_label_sequence_no;

// ---------------------------------------------------------------------------
target_init() {

    target_string_table_length = 0;
    target_label_sequence_no = 0;
}

// ---------------------------------------------------------------------------
// 
target_program_begin() {
    writeln("");
    writeln("var A;");
    writeln("var X;");
    writeln("var BP;");
    writeln("var RAM = [];");
    writeln("");
    writeln("function loadi       (n) { A = n; }");
    writeln("");
    writeln("function load        (n) { A = RAM[n]; }");
    writeln("function store       (n) { RAM[n] = A; }");
    writeln("");
    writeln("function add         (n) { A += RAM[n]; }");
    writeln("function subtract    (n) { A -= RAM[n]; }");
    writeln("function multiply    (n) { A *= RAM[n]; }");
    writeln("function divide      (n) { A = (A / RAM[n]) | 0; }");
    writeln("");
    writeln("function loadx       ()  { X = A; }");
    writeln("function movebp      (n) { BP += n; }");
    writeln("");
    writeln("function less        ()  { return A > 0; }");
    writeln("function greater     ()  { return A < 0; }");
    writeln("function equals      ()  { return A == 0; }");
    writeln("function notequals   ()  { return A != 0; }");
    writeln("function always      ()  { return true; }");
    writeln("");
    writeln("var global;");
    writeln("");
}
// ---------------------------------------------------------------------------
// 
target_program_end(int global_data_size) {
    int i;
    int ch;
    char s[Str_size];
    int memory_size;

    memory_size = target_string_table_length + Target_local_storage_size + global_data_size;

    writeln("");
    writeln("");

    writeln("function init_memory() {");

    write("global = ");
    int_to_str(memory_size, s);
    write(s);
    writeln(";");
    writeln("");

    write("BP = ");
    int_to_str(target_string_table_length, s);
    write(s);
    writeln(";");
    writeln("");

    writeln("RAM = [");

    i = 0;
    while (i < target_string_table_length) {
        ch = target_string_table[i];

        if (ch == '\\' || ch == '\'' || ch == '\"' ) { 
            copy(s, "\"\\ \"");
            s[2] = ch;
            append(s,".charCodeAt(0)");
        }
        else if (ch >= ' ' && ch <= '~') {
            copy(s, "\" \"");
            s[1] = ch;
            append(s,".charCodeAt(0)");
        }
        else {
            int_to_str(ch, s);
        }

        i = i + 1;
        if (i < target_string_table_length) {
            append(s, ",");
        }

        writeln(s);
    }

    writeln("];");
    writeln("");


    write("for (i = ");
    int_to_str(target_string_table_length, s);
    write(s);
    write("; i < ");
    int_to_str(memory_size, s);
    write(s);
    writeln("; i ++) {");
    writeln("RAM[i] = 0;");
    writeln("}");
    writeln("}");
} 


// ---------------------------------------------------------------------------
// 
target_comment_print(char comment_block[]) {
    int i;
    char line[Str_size];

    i = 0;
    copy(line, "");

    while (comment_block[i] != 0) {

        if (str_equals(line, "")) {
            fill_until_col(line, 60);
            append(line, "// ");
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
// 
target_instruction_print_line(char field1[], char field2[]) {
    char line[Str_size];

    copy(line, "");

    append(line, " ");
    fill_until_col(line, 24);

    append(line, field1);
    append(line, " ");
    fill_until_col(line, 42);
    append(line, field2);

    writeln(line);
}

// ---------------------------------------------------------------------------
target_instruction_branch(char condition[], char label[], char label_postfix[], char loop_control_statement[]) {
    char instruction[Str_size];
    char operand_field[Str_size];

    copy(instruction, "if(");
    append(instruction, condition);
    append(instruction, "())");
        
    copy(operand_field, loop_control_statement);
    append(operand_field, " ");
    append(operand_field, label);
    append(operand_field, label_postfix);
    append(operand_field, ";");

    target_instruction_print_line(instruction, operand_field);
}

target_instruction_memory_operand(char instruction[], int operand, int address_mode) {
    char operand_str[Str_size];
    char operand_field[Str_size];

    int_to_str(operand, operand_str);

    if (address_mode == Target_t_global) {
        if (operand < 0) {
            append(operand_str, "+global");
        }
    } else if (address_mode == Target_t_global_ix) {
        if (operand < 0) {
            append(operand_str, "+global");
        }
        append(operand_str, "+X");

    } else if (address_mode == Target_t_local) {
        append(operand_str, "+BP");

    } else if (address_mode == Target_t_local_ix) {
        append(operand_str, "+BP+X");

    } else if (address_mode == Target_t_ix || address_mode == Target_t_indirect) {
        copy(operand_str, "X");

    } else {
        error_internal();
    }

    copy(operand_field, "(");
    append(operand_field, operand_str);
    append(operand_field, ");");

    target_instruction_print_line(instruction, operand_field);
}

// ---------------------------------------------------------------------------
target_instruction_operand(char instruction[], int operand) {
    char operand_str[Str_size];
    char operand_field[Str_size];

    int_to_str(operand, operand_str);

    copy(operand_field, "(");
    append(operand_field, operand_str);
    append(operand_field, ");");

    target_instruction_print_line(instruction, operand_field);
}

target_instruction(char instruction[]) {

    target_instruction_print_line(instruction, "();");
}

// ---------------------------------------------------------------------------
target_op_branch(char label[], char postfix[]) {
    target_instruction_branch("always", label, postfix, "break");
}

target_op_branch_back(char label[], char postfix[]) {
    target_instruction_branch("always", label, postfix, "continue");
}

target_op_branch_if_less(char label[], char postfix[]) {
    target_instruction_branch("less", label, postfix, "break");
}

target_op_branch_if_greater(char label[], char postfix[]) {
    target_instruction_branch("greater", label, postfix, "break");
}

target_op_branch_if_equals(char label[], char postfix[]) {
    target_instruction_branch("equals", label, postfix, "break");
}

target_op_branch_if_not_equals(char label[], char postfix[]) {
    target_instruction_branch("notequals", label, postfix, "break");
}

target_op_branch_if_true(char label[], char postfix[]) {
    target_op_branch_if_not_equals(label, postfix);
}

target_op_branch_if_false(char label[], char postfix[]) {
    target_op_branch_if_equals(label, postfix);
}


// ---------------------------------------------------------------------------
// 
target_op_loadx() {
    target_instruction("loadx");
}

target_op_load_constant(int operand) {
    target_instruction_operand("loadi", operand);
}

target_op_load_address(int operand, int address_mode_type) {
    target_instruction_memory_operand("loadi", operand, address_mode_type);
}

target_op_load(int operand, int address_mode_type) {
    target_instruction_memory_operand("load", operand, address_mode_type);
}

target_op_store(int operand, int address_mode_type) {
    target_instruction_memory_operand("store", operand, address_mode_type);
}

target_op_add(int operand, int address_mode_type) {
    target_instruction_memory_operand("add", operand, address_mode_type);
}

target_op_subtract(int operand, int address_mode_type) {
    target_instruction_memory_operand("subtract", operand, address_mode_type);
}

target_op_multiply (int operand, int address_mode_type) {
    target_instruction_memory_operand("multiply", operand, address_mode_type);
}

target_op_divide(int operand, int address_mode_type) {
    target_instruction_memory_operand("divide", operand, address_mode_type);
}

target_op_test() {
}

// ---------------------------------------------------------------------------
target_op_subroutine_begin(char function_name[], int argument_count, int local_frame_size) {

    write("function ");
    writeln(function_name);
    writeln("(){");
}

target_op_subroutine_end(char function_name[], int argument_count, int local_frame_size) {

    writeln("return;    }");
}

target_op_call_subroutine(char function_name[], int argument_count, int local_frame_size) {
    char instruction_field[Str_size];

    target_instruction_operand("movebp", argument_count + local_frame_size);

    copy(instruction_field, function_name);
    append(instruction_field, "();");
    target_instruction_print_line(instruction_field, "");

    target_instruction_operand("movebp", -(argument_count + local_frame_size));

}

target_op_pass_argument(int argument_no, int argument_count, int local_frame_size) {

    target_instruction_memory_operand("store", (argument_count + local_frame_size) + (argument_no - 1), Target_t_local);
}

// ---------------------------------------------------------------------------
target_begin_branch_block(char label[], char label_postfix[]) {
        char s[Str_size];

        copy(s, "");
        fill_until_col(s, 45);
        append(s, label);
        append(s, label_postfix);
        append(s, ": {");
        writeln(s);
}

// ---------------------------------------------------------------------------
target_end_branch_block(char label[], char label_postfix[]) {
        write("} // ");
        write(label);
        write(label_postfix);
        writeln(":");
}

// ---------------------------------------------------------------------------
target_begin_back_branch_block(char label[], char label_postfix[]) {

        write(label);
        write(label_postfix);
        writeln(": while(true) {");
}

// ---------------------------------------------------------------------------
target_end_back_branch_block(char label[], char label_postfix[]) {
        char s[Str_size];

        copy(s, "");
        fill_until_col(s, 45);
        append(s, "break; } // ");
        append(s, label);
        append(s, label_postfix);
        append(s, ":");
        writeln(s);
}

// ---------------------------------------------------------------------------
target_built_in_function_debug() {

    target_instruction_print_line("printIntegerNumber", "(A);");
}

target_built_in_function_exit() {

    target_instruction_print_line("abortProgram", "(A);");
}

target_built_in_function_fgetc() {

    target_instruction_print_line("A=readCharCodeFromStdin", "();");
}

target_built_in_function_fputc_stdout() {

    target_instruction_print_line("printCharCodeToStdout", "(A);");
}

target_built_in_function_fputc_stderr() {

    target_instruction_print_line("printCharCodeToStderr", "(A);");
}

// ---------------------------------------------------------------------------
target_allocate_string(char string[], int string_length) {
    int i;
    int address;

    if (target_string_table_length + string_length > Target_string_table_size) {
        error_target("out of initialised (string) storage space");
    }

    i = 0;
    while(i <= string_length) {
        target_string_table[target_string_table_length + i] = string[i];
        i = i + 1;
    }

    address = target_string_table_length;
    target_string_table_length = target_string_table_length + string_length;

    return address;
}

target_allocate_global_address(int offset, int var_size) {
    
    return -offset - var_size;
}

target_allocate_local_address(int offset, int var_size, int function_argument_count) {

    return function_argument_count + offset;
}

target_allocate_function_argument_address(int argument_no, int var_size) {

    return argument_no - 1;
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

