#ifdef LINE_DIRECTIVE
#line 2 "errormessages.h"
#endif

int error_line_no;
int error_line_pos;

char error_file_name[Str_size];

// ---------------------------------------------------------------------------
error_set_line(int line_no, int line_pos) {
    error_line_no = line_no;
    error_line_pos = line_pos;
}

// ---------------------------------------------------------------------------
error_set_file_name(char file_name[]) {
    copy(error_file_name, file_name);
}

// ---------------------------------------------------------------------------
error_print(char err_type[], char msg[]) {
    char str[Str_size];

    write_stderr(err_type); writeln_stderr(msg);

    write_stderr("File: "); writeln_stderr(error_file_name);

    int_to_str(error_line_no, str);
    write_stderr("Line no: "); writeln_stderr(str);

    int_to_str(error_line_pos, str);
    write_stderr("Line pos: "); writeln_stderr(str);
}

// ---------------------------------------------------------------------------
error_compiler(char msg[]) {
    error_print("Compile error: ", msg);
    exit(1);
}

// ---------------------------------------------------------------------------
error_syntax(char msg[]) {
    error_print("Syntax error: ", msg);
    exit(1);
}

// ---------------------------------------------------------------------------
error_parse(char msg[]) {
    error_print("Parse error: ", msg);
    exit(1);
}

// ---------------------------------------------------------------------------
error_preprocessor(char msg[]) {
    error_print("Error while reading source: ", msg);
    exit(1);
}

// ---------------------------------------------------------------------------
error_target(char msg[]) {
    error_print("Code generation error: ", msg);
    exit(1);
}

// ---------------------------------------------------------------------------
error_internal() {
    error_print("Internal error", "");
    exit(1);
}

