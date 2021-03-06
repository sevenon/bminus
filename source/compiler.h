#ifdef LINE_DIRECTIVE
#line 2 "compiler.h"
#endif

// ===========================================================================
//

// ---------------------------------------------------------------------------
enum {
    Compiler_t_integer_pointer,
    Compiler_t_integer,
    Compiler_t_integer_array,
    Compiler_t_integer_constant,
    Compiler_t_function
};

// ---------------------------------------------------------------------------
enum {
    Compiler_t_global,
    Compiler_t_local
};

// ---------------------------------------------------------------------------

enum {
    Compiler_max_identifiers = 8192
};

int compiler_col_value[Compiler_max_identifiers];
int compiler_col_type[Compiler_max_identifiers];
char compiler_col_name[2097152];   // Compiler_max_identifiers * Str_size
char compiler_col_parent[2097152]; // Compiler_max_identifiers * Str_size

int compiler_identifier_table_size;

// ---------------------------------------------------------------------------
char compiler_function_name[Str_size];
int compiler_function_argument_count;
int compiler_function_local_data_size;
int compiler_function_temp_data_size;

// ---------------------------------------------------------------------------
int compiler_global_data_size;

enum {
    Compiler_max_temp_data_size = 8
};

// ---------------------------------------------------------------------------
char compiler_source_chunk[Source_buffer_length];

// ---------------------------------------------------------------------------
int compiler_current_enum_value;

// ---------------------------------------------------------------------------
int compiler_label_sequence_no;

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_init() {

    compiler_identifier_table_size = 0;
    compiler_global_data_size = 0;

    compiler_current_enum_value = 0;
    compiler_label_sequence_no = 0;

    copy(compiler_function_name, "");
    compiler_function_argument_count = 0;
    compiler_function_local_data_size = 0;
    compiler_function_temp_data_size = 0;
}

// ===========================================================================
compiler_get_current_scope() {
    if (! str_equals(compiler_function_name, "")) {
        return Compiler_t_local;
    }

    return Compiler_t_global;
}

// ===========================================================================
//
compiler_find_identifier_with_parent(char name[], char parent[], int out_value[], int out_type[]) {
    int i;
    char str[Str_size];

    i = 0;
    while (i < compiler_identifier_table_size) {
        copy_from(str, compiler_col_name, i * Str_size);
        if (str_equals(str, name)) {
            out_value[0] = compiler_col_value[i];
            out_type[0] = compiler_col_type[i];
            copy_from(str, compiler_col_parent, i * Str_size);
            if (str_equals(str, parent)) {
                return True;
            }
        }
        i = i + 1;
    }

    return False;
}

// ---------------------------------------------------------------------------
compiler_find_identifier(char name[], int out_value[], int out_type[], int out_scope[]) {

    if (compiler_get_current_scope() == Compiler_t_local) {
        if (compiler_find_identifier_with_parent(name, compiler_function_name, out_value, out_type)) {
            out_scope[0] = Compiler_t_local;
            return True;
        }
    }

    if (compiler_find_identifier_with_parent(name, "", out_value, out_type)) {
        out_scope[0] = Compiler_t_global;
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
compiler_identifier_must_not_be_defined_in_current_scope(char name[]) {
    int value[1];
    int type[1];
    int scope[1];

    if (! compiler_find_identifier(name, value, type, scope)) {
        return;
    }

    if (scope[0] == compiler_get_current_scope())  {
        error_compiler("name already defined");
    }
}

// ---------------------------------------------------------------------------
compiler_add_identifier(char name[], int type, int value) {

    compiler_identifier_must_not_be_defined_in_current_scope(name);

    if (compiler_identifier_table_size >= Compiler_max_identifiers) {
        error_compiler("out of symbol table space");
    }

    copy_to(compiler_col_name, name, compiler_identifier_table_size * Str_size);
    copy_to(compiler_col_parent, compiler_function_name, compiler_identifier_table_size * Str_size);
    compiler_col_type[compiler_identifier_table_size] = type;
    compiler_col_value[compiler_identifier_table_size] = value;

    compiler_identifier_table_size = compiler_identifier_table_size + 1;
}

// ---------------------------------------------------------------------------
compiler_must_find_identifier(char name[], int out_type[], int out_scope[]) {
    int value[1];

    if (! compiler_find_identifier(name, value, out_type, out_scope)) {
        error_compiler("name not defined");
    }

    return value[0];
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_allocate_temp_local() {
    int temp_local_address;
    int offset;
    
    if (compiler_function_temp_data_size >= Compiler_max_temp_data_size) {
        error_compiler("too many local temporary variables");
    }

    offset = compiler_function_local_data_size + compiler_function_temp_data_size;
    temp_local_address = target_allocate_local_address(offset, 1, compiler_function_argument_count);

    compiler_function_temp_data_size = compiler_function_temp_data_size + 1;

    return temp_local_address;
}

// ---------------------------------------------------------------------------
compiler_free_temp_local(int temp_local_address) {
    int sanity_check_address;
    int offset;
    
    compiler_function_temp_data_size = compiler_function_temp_data_size - 1;

    offset = compiler_function_local_data_size + compiler_function_temp_data_size;
    sanity_check_address = target_allocate_local_address(offset, 1, compiler_function_argument_count);

    if (temp_local_address != sanity_check_address) {
        error_internal();
    }
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_get_label(char start_with[], char out_label[]) {
    char sequence_no_str[Str_size];

    int_to_str(compiler_label_sequence_no, sequence_no_str);
    copy(out_label, start_with);
    append(out_label, "_");
    append(out_label, sequence_no_str);

    compiler_label_sequence_no = compiler_label_sequence_no + 1;
}


// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_enumerator(char name[]) {

    compiler_identifier_must_not_be_defined_in_current_scope(name);

    compiler_add_identifier(name, Compiler_t_integer_constant, compiler_current_enum_value);
    compiler_current_enum_value = compiler_current_enum_value + 1;
}

// ---------------------------------------------------------------------------
compiler_enumerator_assigned_value(char name[], char value[]) {

    compiler_current_enum_value = str_to_int(value);
    compiler_enumerator(name);
}

// ---------------------------------------------------------------------------
compiler_enumerator_list_end() {

    compiler_current_enum_value = 0;
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_declaration_integer(char variable_name[]) {
    int address;

    if (compiler_get_current_scope() == Compiler_t_local) {
        address = target_allocate_local_address(compiler_function_local_data_size, 1, compiler_function_argument_count);
        compiler_function_local_data_size = compiler_function_local_data_size + 1;
        compiler_add_identifier(variable_name, Compiler_t_integer, address);
        return;
    }

    if (compiler_get_current_scope() == Compiler_t_global) {
        address = target_allocate_global_address(compiler_global_data_size, 1);
        compiler_global_data_size = compiler_global_data_size + 1;
        compiler_add_identifier(variable_name, Compiler_t_integer, address);
        return;
    }

    error_internal();
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_declaration_integer_array(char array_name[], int array_length) {
    int address;

    if (array_length <= 0) {
        error_compiler("array length must be greater than zero");
    }

    if (compiler_get_current_scope() == Compiler_t_local) {
        address = target_allocate_local_address(compiler_function_local_data_size, array_length, compiler_function_argument_count);
        compiler_function_local_data_size = compiler_function_local_data_size + array_length;
        compiler_add_identifier(array_name, Compiler_t_integer_array, address);
        return;
    }

    if (compiler_get_current_scope() == Compiler_t_global) {
        address = target_allocate_global_address(compiler_global_data_size, array_length);
        compiler_global_data_size = compiler_global_data_size + array_length;
        compiler_add_identifier(array_name, Compiler_t_integer_array, address);
        return;
    }

    error_internal();
}

// ---------------------------------------------------------------------------
compiler_declaration_integer_array_constant_length_specifier(char array_name[], char array_length_integer_constant[])  {
    int length;

    length = str_to_int(array_length_integer_constant);
    compiler_declaration_integer_array(array_name, length);
}

// ---------------------------------------------------------------------------
compiler_declaration_integer_array_identifier_length_specifier(char array_name[], char array_length_identifier[])  {
    int array_length;
    int type[1];
    int scope[1];

    array_length = compiler_must_find_identifier(array_length_identifier, type, scope);

    if (type[0] != Compiler_t_integer_constant) {
        error_compiler("constant array length specifier expected");
    }

    compiler_declaration_integer_array(array_name, array_length);
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
// 
// ---------------------------------------------------------------------------
compiler_function_definition_begin(char function_name[]) {

    compiler_identifier_must_not_be_defined_in_current_scope(function_name);
    compiler_add_identifier(function_name, Compiler_t_function, 0);

    copy(compiler_function_name, function_name);
    compiler_function_local_data_size = 0;
    compiler_function_temp_data_size = 0;
    compiler_function_argument_count = 0;
}

// ---------------------------------------------------------------------------
compiler_function_argument_declaration_item(char argument_name[], int argument_type, int argument_no) {
    int address;

    compiler_function_argument_count = compiler_function_argument_count + 1;

    address = target_allocate_function_argument_address(argument_no, 1);
    compiler_add_identifier(argument_name, argument_type, address);
}
    
// ---------------------------------------------------------------------------
compiler_function_compound_statement_locals_declared() {

    target_op_subroutine_begin(compiler_function_name,
                               compiler_function_argument_count,
                               compiler_function_local_data_size + Compiler_max_temp_data_size);
    
    target_begin_branch_block(compiler_function_name, "_end");
}

// ---------------------------------------------------------------------------
compiler_function_definition_end() {

    target_end_branch_block(compiler_function_name, "_end");

    target_op_subroutine_end(compiler_function_name,
                             compiler_function_argument_count,
                             compiler_function_local_data_size + Compiler_max_temp_data_size);

    copy(compiler_function_name, "");

    if (compiler_function_temp_data_size != 0) {
        error_internal();
    }
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_program_begin() {

    target_program_begin();
}

compiler_program_end() {

    target_program_end(compiler_global_data_size);
}

// ---------------------------------------------------------------------------
compiler_output_source_as_comment() {

    preprocessor_get_source_chunk(compiler_source_chunk);

    target_comment_print(compiler_source_chunk);
}

// ===========================================================================
//
// ---------------------------------------------------------------------------

compiler_built_in_function_fgetc() {

    target_built_in_function_fgetc();
}

compiler_built_in_function_fputc_stdout() {

    target_built_in_function_fputc_stdout();
}

compiler_built_in_function_fputc_stderr() {

    target_built_in_function_fputc_stderr();
}

compiler_built_in_function_exit() {

    target_built_in_function_exit();
}

compiler_built_in_function_debug() {

    target_built_in_function_debug();
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_function_call_prepare(char function_name[], char out_function_name_cookie[]) {

    copy(out_function_name_cookie, function_name);
}


// ---------------------------------------------------------------------------
compiler_function_call_string_literal_argument(char string_literal[]) {
    int string_length;
    int address;

    string_length = length(string_literal);
    address = target_allocate_string(string_literal, string_length + 1);

    target_op_load_address(address, Target_t_global);
}

// ---------------------------------------------------------------------------
compiler_function_call_pointer_argument(char identifier[]) {
    int value[1];
    int type[1];
    int scope[1];

    if (! compiler_find_identifier(identifier, value, type, scope)) {
        return False;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
        target_op_load_address(value[0], Target_t_local);
        return True;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
        target_op_load_address(value[0], Target_t_global);
        return True;
    }

    if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
        target_op_load(value[0], Target_t_local);
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
compiler_function_call_argument_prepare(int out_argument_temp_local_cookie[]) {
    int temp_local;

    temp_local = compiler_allocate_temp_local();
    target_op_store(temp_local, Target_t_local);

    out_argument_temp_local_cookie[0] = temp_local;
}

// ---------------------------------------------------------------------------
compiler_function_call_argument_pass(int argument_number, int argument_count, int argument_temp_local_cookie[]) {

    target_op_load(argument_temp_local_cookie[0], Target_t_local);
    
    target_op_pass_argument(argument_number,
                            argument_count,
                            compiler_function_local_data_size + Compiler_max_temp_data_size);

    compiler_free_temp_local(argument_temp_local_cookie[0]);
}

// ---------------------------------------------------------------------------
compiler_function_call_execute(char function_name_cookie[], int function_argument_count) {

    target_op_call_subroutine(function_name_cookie,
                              function_argument_count,
                              compiler_function_local_data_size + Compiler_max_temp_data_size);
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_primary_expression_array_index() {

    target_op_loadx();
}

// ---------------------------------------------------------------------------
compiler_primary_expression_identifier(char identifier[]) {
    int value;
    int type[1];
    int scope[1];
    int temp_array_index;

    value = compiler_must_find_identifier(identifier, type, scope);

    if (type[0] == Compiler_t_integer_constant) {
        target_op_load_constant(value);
        return;
    }

    if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_local) {
        target_op_load(value, Target_t_local);
        return;
    }

    if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_global) {
        target_op_load(value, Target_t_global);
        return;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
        target_op_load(value, Target_t_local_ix);
        return;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
        target_op_load(value, Target_t_global_ix);
        return;
    }

    if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
        temp_array_index = compiler_allocate_temp_local();
        target_op_load_address(0, Target_t_ix);                 // temp_array_index = X
        target_op_store(temp_array_index, Target_t_local);
        target_op_load(value, Target_t_local);                  // A = address held in local pointer variable
        target_op_add(temp_array_index, Target_t_local);        // X = A + temp_array_index
        target_op_loadx();
        target_op_load(0, Target_t_indirect);                         // load (X)
        compiler_free_temp_local(temp_array_index);
        return;
    }

    error_compiler("identifier cannot be used in an expression");
}

// ---------------------------------------------------------------------------
compiler_primary_expression_integer_constant(char integer_constant_str[]) {
    int integer_constant;

    integer_constant = str_to_int(integer_constant_str);
    target_op_load_constant(integer_constant);
}

// ---------------------------------------------------------------------------
compiler_primary_expression_character_constant(int character_code) {

    target_op_load_constant(character_code);
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_unary_expression(char operator_text[]) {
    int temp_local;
    char label[Str_size];

    if (str_equals(operator_text, "+")) {
        return;
    }

    if (str_equals(operator_text, "-")) {
        temp_local = compiler_allocate_temp_local();
        target_op_store(temp_local, Target_t_local);
        target_op_load_constant(0);
        target_op_subtract(temp_local, Target_t_local);
        compiler_free_temp_local(temp_local);
        return;
    }

    if (str_equals(operator_text, "!")) {
        target_get_label("logical_not", label);
        target_begin_branch_block(label, "_true");
        target_begin_branch_block(label, "_false");
        target_op_test();
        target_op_branch_if_true(label, "_false");
        target_op_load_constant(1);
        target_op_branch(label, "_true");
        target_end_branch_block(label, "_false");
        target_op_load_constant(0);
        target_end_branch_block(label, "_true");
        return;
    }

    error_internal();
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_multiplicative_expression_sequence_begin() {
    int temp_left_cookie;

    temp_left_cookie = compiler_allocate_temp_local();
    target_op_store(temp_left_cookie, Target_t_local);

    return temp_left_cookie;
}

// ---------------------------------------------------------------------------
compiler_multiplicative_expression_sequence_end(char operator_text[], int temp_left_cookie) {
    int temp_right;

    if (str_equals(operator_text, "*")) {
        target_op_multiply(temp_left_cookie, Target_t_local);
        compiler_free_temp_local(temp_left_cookie);
        return;
    }

    if (str_equals(operator_text, "/")) {
        temp_right = compiler_allocate_temp_local();
        target_op_store(temp_right, Target_t_local);
        target_op_load(temp_left_cookie, Target_t_local);
        target_op_divide(temp_right, Target_t_local);
        compiler_free_temp_local(temp_right);
        compiler_free_temp_local(temp_left_cookie);
        return;
    }

    error_internal();
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_additive_expression_sequence_begin() {
    int temp_left_cookie;

    temp_left_cookie = compiler_allocate_temp_local();
    target_op_store(temp_left_cookie, Target_t_local);

    return temp_left_cookie;
}

// ---------------------------------------------------------------------------
compiler_additive_expression_sequence_end(char operator_text[], int temp_left_cookie) {
    int temp_right;

    if (str_equals(operator_text, "+")) {
        target_op_add(temp_left_cookie, Target_t_local);
        compiler_free_temp_local(temp_left_cookie);
        return;
    }

    if (str_equals(operator_text, "-")) {
        temp_right = compiler_allocate_temp_local();
        target_op_store(temp_right, Target_t_local);
        target_op_load(temp_left_cookie, Target_t_local);
        target_op_subtract(temp_right, Target_t_local);
        compiler_free_temp_local(temp_right);
        compiler_free_temp_local(temp_left_cookie);
        return;
    }

    error_internal();
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_relational_or_equality_expression_sequence_begin() {
    int temp_left_cookie;

    temp_left_cookie = compiler_allocate_temp_local();
    target_op_store(temp_left_cookie, Target_t_local);

    return temp_left_cookie;
}

// ---------------------------------------------------------------------------
compiler_relational_or_equality_expression_sequence_end(char operator_text[], int temp_left_cookie) {
    char label[Str_size];

    target_get_label("compare", label);

    target_op_subtract(temp_left_cookie, Target_t_local);
    compiler_free_temp_local(temp_left_cookie);

    target_begin_branch_block(label, "_false");
    target_begin_branch_block(label, "_true");

    if (str_equals(operator_text, "==")) {
        target_op_branch_if_equals(label, "_true");
    }
    else if (str_equals(operator_text, "!=")) {
        target_op_branch_if_not_equals(label, "_true");
    }
    else if (str_equals(operator_text, "<")) {
        target_op_branch_if_less(label, "_true");
    }
    else if (str_equals(operator_text, "<=")) {
        target_op_branch_if_less(label, "_true");
        target_op_branch_if_equals(label, "_true");
    }
    else if (str_equals(operator_text, ">")) {
        target_op_branch_if_greater(label, "_true");
    }
    else if (str_equals(operator_text, ">=")) {
        target_op_branch_if_greater(label, "_true");
        target_op_branch_if_equals(label, "_true");
    }
    else {
        error_internal();
    }

    target_op_load_constant(0);
    target_op_branch(label, "_false");
    target_end_branch_block(label, "_true");
    target_op_load_constant(1);
    target_end_branch_block(label, "_false");
}

// ===========================================================================
// ---------------------------------------------------------------------------
compiler_logical_and_expression_begin(char out_label_and[]) {

    target_get_label("logical_and", out_label_and);
    target_begin_branch_block(out_label_and, "_true");
    target_begin_branch_block(out_label_and, "_false");

    target_op_test();
    target_op_branch_if_false(out_label_and, "_false");
}

// ---------------------------------------------------------------------------
compiler_logical_and_switch_sequence(char label_and[]) {

    target_op_test();
    target_op_branch_if_false(label_and, "_false");
}

// ---------------------------------------------------------------------------
compiler_logical_and_expression_end(char label_and[]) {

    target_op_load_constant(1);
    target_op_branch(label_and, "_true");
    target_end_branch_block(label_and, "_false");
    target_op_load_constant(0);
    target_end_branch_block(label_and, "_true");
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_logical_or_expression_begin(char out_label_or[]) {

    target_get_label("logical_or", out_label_or);
    target_begin_branch_block(out_label_or, "_false");
    target_begin_branch_block(out_label_or, "_true");


    target_op_test();
    target_op_branch_if_true(out_label_or, "_true");
}

// ---------------------------------------------------------------------------
compiler_logical_or_switch_sequence(char label_or[]) {

    target_op_test();
    target_op_branch_if_true(label_or, "_true");
}

// ---------------------------------------------------------------------------
compiler_logical_or_expression_end(char label_or[]) {

    target_op_load_constant(0);
    target_op_branch(label_or, "_false");
    target_end_branch_block(label_or, "_true");
    target_op_load_constant(1);
    target_end_branch_block(label_or, "_false");
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_return_statement() {

    target_op_branch(compiler_function_name, "_end");
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_assignment_statement(char variable_name[]) {
    int value;
    int type[1];
    int scope[1];
    int temp_rvalue;
    int temp_array_index;

    value = compiler_must_find_identifier(variable_name, type, scope);

    if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_global) {
        target_op_store(value, Target_t_global);
        return;
    }

    if (type[0] == Compiler_t_integer && scope[0] == Compiler_t_local) {
        target_op_store(value, Target_t_local);
        return;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_global) {
        target_op_store(value, Target_t_global_ix);
        return;
    }

    if (type[0] == Compiler_t_integer_array && scope[0] == Compiler_t_local) {
        target_op_store(value, Target_t_local_ix);
        return;
    }

    if (type[0] == Compiler_t_integer_pointer && scope[0] == Compiler_t_local) {
        temp_rvalue = compiler_allocate_temp_local();
        temp_array_index = compiler_allocate_temp_local();
        target_op_store(temp_rvalue, Target_t_local);       // temp_rvalue = A
        target_op_load_address(0, Target_t_ix);             // temp_array_index = X
        target_op_store(temp_array_index, Target_t_local);
        target_op_load(value, Target_t_local);              // A = address held in local pointer variable
        target_op_add(temp_array_index, Target_t_local);    // X = A + temp_array_index
        target_op_loadx();                          
        target_op_load(temp_rvalue, Target_t_local);        // (X) = temp_rvalue
        target_op_store(0, Target_t_indirect);
        compiler_free_temp_local(temp_array_index);
        compiler_free_temp_local(temp_rvalue);
        return;
    }

    error_compiler("left hand side of assignment statement must be an integer identifier or array element");
}

// ---------------------------------------------------------------------------
compiler_assignment_statement_array_begin(int out_temp_array_index_cookie[]) {

    out_temp_array_index_cookie[0] = compiler_allocate_temp_local();
    target_op_store(out_temp_array_index_cookie[0], Target_t_local);
}

// ---------------------------------------------------------------------------
compiler_assignment_statement_array_end(int temp_array_index_cookie[]) {
    int temp_expression;

    temp_expression = compiler_allocate_temp_local();

    target_op_store(temp_expression, Target_t_local);
    target_op_load(temp_array_index_cookie[0], Target_t_local);
    target_op_loadx();
    target_op_load(temp_expression, Target_t_local);

    compiler_free_temp_local(temp_expression);
    compiler_free_temp_local(temp_array_index_cookie[0]);
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_while_statement_begin(char out_label_while[]) {

    target_get_label("while", out_label_while);
    target_begin_branch_block(out_label_while, "_end");
    target_begin_back_branch_block(out_label_while, "_test");
}

// ---------------------------------------------------------------------------
compiler_while_statement_end(char label_while[]) {

    target_op_branch_back(label_while, "_test");
    target_end_back_branch_block(label_while, "_test");
    target_end_branch_block(label_while, "_end");
}

// ---------------------------------------------------------------------------
compiler_while_statement_test(char label_while[]) {

    target_op_test();
    target_op_branch_if_false(label_while, "_end");
}

// ===========================================================================
//
// ---------------------------------------------------------------------------
compiler_if_statement_test_fn(char out_label_if[]) {

    target_get_label("if", out_label_if);

    target_op_test();
    target_begin_branch_block(out_label_if, "_end");
    target_begin_branch_block(out_label_if, "_next");
    target_op_branch_if_false(out_label_if, "_next");
}

// ---------------------------------------------------------------------------
compiler_if_statement_else_fn(char label_if[]) {

    target_op_branch(label_if, "_end");
    target_end_branch_block(label_if, "_next");
}

// ---------------------------------------------------------------------------
compiler_if_statement_no_else_fn(char label_if[]) {

    target_end_branch_block(label_if, "_next");
    target_end_branch_block(label_if, "_end");
}

// ---------------------------------------------------------------------------
compiler_if_statement_else_end_fn(char label_if[]) {

    target_end_branch_block(label_if, "_end");
}
