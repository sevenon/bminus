#ifndef VC_IDE
#line 2 "globals.h"
#endif

enum {
    False = 0,
    True = 1
};

enum {
    Str_size = 256,
    Source_buffer_length = 1048576
};

#ifndef _MSC_VER
#line 2 "stringlib.h"
#endif

// ---------------------------------------------------------------------------
write(char str[]) {
	int i;

	i = 0;
	while (str[i] != 0) {
		fputc(str[i], stdout);
		i = i + 1;
	}
}

// ---------------------------------------------------------------------------
writeln(char str[]) {
	write(str);
	fputc('\n', stdout);
}

// ---------------------------------------------------------------------------
write_stderr(char str[]) {
	int i;

	i = 0;
	while (str[i] != 0) {
		fputc(str[i], stderr);
		i = i + 1;
	}
}

// ---------------------------------------------------------------------------
writeln_stderr(char str[]) {
	write_stderr(str);
	fputc('\n', stderr);
}

// ---------------------------------------------------------------------------
readln(char line[], int max_chars) {
    int i;
    int c;

    i = 0;
    c = 0;
    line[i] = 0;
    while (i < max_chars && c != '\n' && c != -1) {
        c = fgetc(stdin);
        if (c != -1 && c != '\r') {
            line[i] = c;
            line[i + 1] = 0;
            i = i + 1;
        }
    }
    return i;
}
// ---------------------------------------------------------------------------
starts_with(char str[], char with_str[]) {
	int i;

	i = 0;
	while (str[i] != 0 && str[i] == with_str[i]) {
		i = i + 1;
    }

    if (with_str[i] == 0) {
	    return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
str_equals(char str1[], char str2[]) {
	int i;

	i = 0;
	while (str1[i] == str2[i]) {
		if (str1[i] == 0 && str2[i] == 0) {
			return True;
        }
		if (str1[i] == 0 || str2[i] == 0) {
			return False;
        }
		i = i + 1;
	}

	return False;
}

// ---------------------------------------------------------------------------
copy_pos(char dest[], char src[], int dest_pos, int src_pos) {
	int i;

	i = 0;
	while (src[i + src_pos] != 0) {
		dest[i + dest_pos] = src[i + src_pos];
		i = i + 1;
	}

	dest[i + dest_pos] = 0;
}

// ---------------------------------------------------------------------------
copy(char dest[], char src[]) {

    copy_pos(dest, src, 0, 0);
}

// ---------------------------------------------------------------------------
copy_from(char dest[], char src[], int src_pos) {

    copy_pos(dest, src, 0, src_pos);
}

// ---------------------------------------------------------------------------
copy_to(char dest[], char src[], int dest_pos) {

    copy_pos(dest, src, dest_pos, 0);
}

// ---------------------------------------------------------------------------
append(char dest[], char src[]) {
    int dest_length;

    dest_length = length(dest);
    copy_to(dest, src, dest_length);
}

// ---------------------------------------------------------------------------
append_char(char dest[], int c) {
    char s[2];

    s[0] = c;
    s[1] = 0;
    append(dest, s);
}

// ---------------------------------------------------------------------------
fill_until_col(char str[], int col) {
	int i;

    i = length(str);
	while (i < col) {
        str[i] = ' ';
        i = i + 1;
    }

    str[i] = 0;
}

// ---------------------------------------------------------------------------
contains(char str[], char substr[]) {
	int i;
	int j;
	int k;

	if(substr[0] == 0) {
		return True;
    }

	i = 0;
	while (str[i] != 0) {
		j = i;
		k = 0;
		while (str[j] == substr[k]) {
			j = j + 1;
			k = k + 1;
			if (substr[k] == 0) {
				return True;
            }
		}
		i = i + 1;
	}

	return False;
}

// ---------------------------------------------------------------------------
contains_char(char str[], int c) {
    char s[2];

    s[0] = c;
    s[1] = 0;
    return contains(str, s);
}

// ---------------------------------------------------------------------------
length(char str[]) {
	int i;

	i = 0;
	while (str[i] != 0) {
		i = i + 1;
    }

	return i;
}

// ---------------------------------------------------------------------------
str_to_int(char str[]) {
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i] != 0) {
		n = n * 10 + (str[i] - '0');
		i = i + 1;
	}

	return n;
}

// ---------------------------------------------------------------------------
int_to_str(int n, char str[]) {
    int pos;
    int endpos;
	int n_mod_10;
    int absn;
    char tmp_str[Str_size];

    absn = n;
    if (absn < 0) {
        absn = -absn;
    }

    pos = Str_size - 1;
    tmp_str[pos] = 0;
    endpos = pos;
	while (pos == endpos || absn != 0) {
		n_mod_10 = absn - (10 * ( absn / 10));
		pos = pos - 1;
		tmp_str[pos] = '0' + n_mod_10;
		absn = absn / 10;
	}

    if (n < 0) {
		pos = pos - 1;
        tmp_str[pos] = '-';
    }

    copy_from(str, tmp_str, pos);
}
#ifndef _MSC_VER
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

#ifndef _MSC_VER
#line 2 "preprocessor.h"
#endif


// ---------------------------------------------------------------------------
char file_name[Str_size];

int line_no;
int line_pos;

char line[Str_size];
int line_length;

char source_buffer[Source_buffer_length];

// ---------------------------------------------------------------------------
preprocessor_init() {
    line_no = 0;
    line_pos = 0;
    copy(source_buffer, "");
    copy(file_name, "N/A");
}

// ---------------------------------------------------------------------------
preprocessor_get_line_no() {
    return line_no;
}

// ---------------------------------------------------------------------------
preprocessor_get_line_pos() {
    return line_pos;
}

// ---------------------------------------------------------------------------
preprocessor_get_source_chunk(char src[]) {
    copy(src, source_buffer);
    copy(source_buffer, "");
}

// ---------------------------------------------------------------------------
preprocessor_read_next_line() {
    int chars_read;

    chars_read = readln(line, Str_size - 1);
    if (chars_read == Str_size - 1) {
        error_preprocessor("line too long");
    }

    if (str_equals(line, ""))
        return False;

    line_no = line_no + 1;
    line_pos = 0;
    line_length = length(line);

    append(source_buffer, line);
    return True;
}

// ---------------------------------------------------------------------------
preprocessor_read_char() {
    int c;

    if (line_pos >= line_length)
        return '\n';

    c = line[line_pos];

    line_pos = line_pos + 1;
    return c;
}

// ---------------------------------------------------------------------------
preprocessor_lookahead1() {
    if (line_pos >= line_length)
        return '\n';

    return line[line_pos];
}

// ---------------------------------------------------------------------------
preprocessor_lookahead2() {
    if (line_pos + 1 >= line_length)
        return '\n';

    return line[line_pos + 1];
}

// ---------------------------------------------------------------------------
preprocessor_compiler_directive() {
    int i;

    if (starts_with(line, "#line 2 ")) {
        line_no = 2;

        copy(file_name, "");
        i = length("#line 2 ");

        while (line[i] != ' ' && line[i] != '\n' && line[i] != 0) {
            append_char(file_name, line[i]);
            i = i + 1; 
        }
		error_set_file_name(file_name);
        error_set_line(2, 0);
	}
}

// ---------------------------------------------------------------------------
preprocessor_skip() {
    int c;
    int c1;

    if (line_pos >= line_length) {
        if (! preprocessor_read_next_line())
            return False;

        if (line_length == 0)
            return preprocessor_skip();

        if (starts_with(line, "#")) {
            preprocessor_compiler_directive();

            line_pos = 0;
            line_length = 0;
            return preprocessor_skip();
        }
    }

    c = line[line_pos];
    c1 = line[line_pos + 1];

    if (c == ' ' || c == '\t' || c == '\n') {
        line_pos = line_pos + 1;
        return preprocessor_skip();
    }

    if (c == '/' && c1 == '/') {
        line_pos = 0;
        line_length = 0;
        return preprocessor_skip();
    }

    return True;
}

#ifndef _MSC_VER
#line 2 "token.h"
#endif

// ---------------------------------------------------------------------------
//
// token
//             integer-constant
//             character-constant
//             string-literal
//             identifier-or-keyword
//             symbol
//
// integer-constant
//             digit-list
//
// character-constant
//             ' char-escape-sequence '
//             ' any-except ' '
//            
// digit-list
//             digit digit-list
//             digit
//
// digit
//             one-of 0 1 2 3 4 5 6 7 8 9
//            
// string-literal
//             " string-literal-char-sequence "
//
// string-literal-char-sequence
//             string-literal-char string-literal-char-sequence
//             string-literal-char
//
// string-literal-char
//             char-escape-sequence
//             any-char-except "
//
// char-escape-sequence
//             one-of \n \r \t \\ \' \"
//
// identifier-or-keyword
//             identifier-nondigit-char identifier-any-char-sequence
//             identifier-nondigit-char
//            
// identifier-nondigit-char
//             one-of _ a b c d e f g h i j k l m n o p q r s t u v w x y z
//                      A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//            
// identifier-any-char
//             one-of _ a b c d e f g h i j k l m n o p q r s t u v w x y z
//                      A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//                      0 1 2 3 4 5 6 7 8 9
//           
// identifier-any-char-sequence
//             identifier-any-char identifier-any-char-sequence
//             identifier-any-char
// 
// symbol
//             one-of  < > + - / * = <= >= ( ) { } [ ] != == ; , 
//
// keyword
//             one-of  const int char if else while enum debug
//
// ---------------------------------------------------------------------------

int token_type;
int token_lookahead_type;

int token_line_no;
int token_lookahead_line_no;

int token_line_pos;
int token_lookahead_line_pos;

char token_text[Str_size];
char token_lookahead_text[Str_size];

enum {
    Token_t_invalid,
    Token_t_character_constant,
    Token_t_integer_constant,
    Token_t_string_literal,
    Token_t_identifier,
    Token_t_symbol,
    Token_t_keyword,
    Token_t_eof
};

// ---------------------------------------------------------------------------
token_init() {
    token_line_no = 0;
    token_line_pos = 0;
    token_lookahead_line_no = 0;
    token_lookahead_line_pos = 0;
}

// ---------------------------------------------------------------------------
token_char_escape_sequence() {
    int c1;
    int c2;

    c1 = preprocessor_lookahead1();
    c2 = preprocessor_lookahead2();

    if (c1 != '\\' || c2 == '\n') {
        return False;
    }

    preprocessor_read_char();
    preprocessor_read_char();

    if        (c2 == 'n') {
        c1 = 10;
    } else if (c2 == 'r') {
        c1 = 13;
    } else if (c2 == 't') {
        c1 = 9;
    } else if (c2 == '\\') {
        c1 = 92;
    } else if (c2 == '\'') {
        c1 = 39;
    } else if (c2 == '\"') {
        c1 = 34;
    } else {
        error_parse("invalid character escape sequence");
    }

    append_char(token_lookahead_text, c1);
    return True;
}

// ---------------------------------------------------------------------------
token_string_literal_char() {
    int c1;

    if (token_char_escape_sequence()) {
        return True;
    }

    c1 = preprocessor_lookahead1();
    if (c1 != '"') {
        append_char(token_lookahead_text, c1);
        preprocessor_read_char();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_string_literal_char_sequence() {

    if (token_string_literal_char()) {
        token_string_literal_char_sequence();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_string_literal() {

    if (preprocessor_lookahead1() != '"') {
        return False;
    }

    preprocessor_read_char();
    token_string_literal_char_sequence();

    if (preprocessor_read_char() != '"') {
        error_parse("string literal not terminated");
    }

    token_lookahead_type = Token_t_string_literal;
    return True;
}

// ---------------------------------------------------------------------------
token_identifier_any_char() {
    int c1;

    c1 = preprocessor_lookahead1();
    if (! contains_char("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", c1)) {
        return False;
    }

    append_char(token_lookahead_text, c1);
    preprocessor_read_char();
    return True;
}

// ---------------------------------------------------------------------------
token_identifier_any_char_sequence() {

    if (! token_identifier_any_char()) {
        return False;
    }

    token_identifier_any_char_sequence();
    return True;
}

// ---------------------------------------------------------------------------
token_identifier_non_digit_char() {
    int c1;

    c1 = preprocessor_lookahead1();
    if (! contains_char("_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", c1)) {
        return False;
    }

    append_char(token_lookahead_text, c1);
    preprocessor_read_char();
    return True;
}

// ---------------------------------------------------------------------------
token_identifier_or_keyword() {
    char tmp_str[Str_size];

    if (! token_identifier_non_digit_char()) {
        return False;
    }

    token_identifier_any_char_sequence();
    copy(tmp_str, " ");
    append(tmp_str, token_lookahead_text);
    append(tmp_str, " ");

    if (contains(" int char if else while enum return ", tmp_str)) {
        token_lookahead_type = Token_t_keyword;
    } else {
        token_lookahead_type = Token_t_identifier;
    }

    return True;
}

// ---------------------------------------------------------------------------
token_character_constant() {
    int c1;

    if (preprocessor_lookahead1() != '\'') {
        return False;
    }

    token_lookahead_type = Token_t_character_constant;
    preprocessor_read_char();

    if (! token_char_escape_sequence()) {
        c1 = preprocessor_read_char();
        append_char(token_lookahead_text, c1);
    }

    c1 = preprocessor_read_char();
    if (c1 != '\'') {
        error_parse("character constant not terminated");
    }

    return True;
}

// ---------------------------------------------------------------------------
token_digit() {
    int c1;

    c1 = preprocessor_lookahead1();

    if (! contains_char("0123456789", c1)) {
        return False;
    }

    c1 = preprocessor_read_char();
    append_char(token_lookahead_text, c1);

    return True;
}

// ---------------------------------------------------------------------------
token_digit_sequence() {
    if (! token_digit()) {
        return False;
    }

    token_digit_sequence();
    return True;
}

// ---------------------------------------------------------------------------
token_integer_constant() {
    if (! token_digit_sequence()) {
        return False;
    }

    token_lookahead_type = Token_t_integer_constant;
    return True;
}

// ---------------------------------------------------------------------------
token_symbol() {
    int c1;
    int c2;

    c1 = preprocessor_lookahead1();
    c2 = preprocessor_lookahead2();

    if (c1 == '<' && c2 == '=' ||
        c1 == '>' && c2 == '=' ||
        c1 == '=' && c2 == '=' ||
        c1 == '!' && c2 == '=' ||
        c1 == '&' && c2 == '&' ||
        c1 == '|' && c2 == '|') {

        copy(token_lookahead_text, "");
        append_char(token_lookahead_text, c1);
        append_char(token_lookahead_text, c2);

        preprocessor_read_char();
        preprocessor_read_char();

        token_lookahead_type = Token_t_symbol;
        return True;
    }

    if (contains_char("<>=+-/*()[]{}!;,", c1)) {
        copy(token_lookahead_text, "");
        append_char(token_lookahead_text, c1);

        token_lookahead_type = Token_t_symbol;

        preprocessor_read_char();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_token() {

    if (token_integer_constant()) {
        return True;
    }

    if (token_character_constant()) {
        return True;
    }

    if (token_string_literal()) {
        return True;
    }

    if (token_identifier_or_keyword()) {
        return True;
    }

    if (token_symbol()) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_get_next() {
    token_lookahead_type = Token_t_invalid;
    copy(token_lookahead_text, "");

    if (! preprocessor_skip()) {
        token_lookahead_type = Token_t_eof;
        return True;
    }

    token_lookahead_line_no = preprocessor_get_line_no();
    token_lookahead_line_pos = preprocessor_get_line_pos();

    if (token_token()) {
        return True;
    }

    token_lookahead_type = Token_t_invalid;
    return False;
}

// ---------------------------------------------------------------------------
token_text_is(char s[]) {
    if (token_type == Token_t_identifier || token_type == Token_t_symbol || token_type == Token_t_keyword) {
        if (str_equals(token_text, s)) {
            return True;
        }
    }

    return False;
}

// ---------------------------------------------------------------------------
token_lookahead_text_is(char s[]) {
    if (str_equals(token_lookahead_text, s)) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_type_is(int t) {
    if (token_type == t) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_lookahead_type_is(int t) {
    if (token_lookahead_type == t) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
token_advance() {
    if (token_lookahead_line_no == 0) {
        token_get_next();
    }

    copy(token_text,token_lookahead_text);
    token_type = token_lookahead_type;
    token_line_no = token_lookahead_line_no;
    token_line_pos = token_lookahead_line_pos;

    error_set_line(token_line_no, token_line_pos);

    token_get_next();
}

// ---------------------------------------------------------------------------
token_advance_if(char s[]) {
    if (token_text_is(s)) {
        token_advance();
        return True;
    }

    return False;
}

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
#ifndef _MSC_VER
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
#ifndef _MSC_VER
#line 2 "syntax.h"
#endif

// C-Subset Syntax 
//
// program
//            global-declaration-list
//
// global-declaration
//            declaration
//            function-definition
//
// global-declaration-list
//            global-declaration global-declaration-list
//            global-declaration
//
// function-definition
//            identifier( function-argument-declaration-list ) function-compound-statement
//            identifier( ) function-compound-statement
//
// function-compound-statement
//            { local-declaration-list statement-list } 
//            { statement-list } 
//
// declaration
//            type-specifier identifier ;
//            type-specifier identifier [ integer-constant ] ;
//            type-specifier identifier [ identifier ] ;
//            enum { enumerator-list } ;
//
// local-declaration-list
//            declaration local-declaration-list
//            declaration
//
// enumerator
//            identifier = integer-constant
//            identifier
//
// enumerator-list
//            enumerator , enumerator-list
//            enumerator
//            
// function-argument-declaration-list
//            function-argument-declaration , function-argument-declaration-list
//            function-argument-declaration
//
// function-argument-declaration
//            type-specifier identifier
//            type-specifier identifier []
//
// type-specifier
//            int
//            char
//
// statement
//           if-statement
//           while-statement
//           compound-statement
//           assignment-statement ;
//           expression-statement ;
//           return-statement ;
//
// statement-list
//            statement statement-list
//            statement
//            
// if-statement
//            if ( expression ) statement else statement
//            if ( expression ) statement
//
// while-statement
//            while ( expression ) statement
//
// assignment-statement
//            identifier = expression
//            identifier [ expression ] = expression
//            
// expression-statement
//           expression
//
// return-statement
//            return expression
//            return
//
// compound-statement
//            { statement-list } 
//
// expression
//            logical-or-expression
//
// logical-or-expression
//            logical-and-expression logical-or-switch-sequence
//            logical-and-expression
//
// logical-or-switch-sequence
//            || logical-and-expression logical-or-switch-sequence
//            || logical-and-expression
//
// logical-and-expression
//            equality-expression logical-and-switch-sequence
//            equality-expression
//
// logical-and-switch-sequence
//            && equality-expression logical-and-switch-sequence
//            && equality-expression
//
// equality-expression
//            relational-expression equality-expression-sequence
//            relational-expression
//
// equality-expression-sequence
//            equality-operator-operator relational-expression equality-expression-sequence
//            equality-operator-operator relational-expression
//
// equality-operator
//            one-of == !=
//
// relational-expression
//            additive-expression relational-expression-sequence
//            additive-expression
//
// relational-expression-sequence
//            relational-operator additive-expression relational-expression-sequence
//            relational-operator additive-expression
//
// relational-operator
//           one-of < <= > >=
//
// additive-expression
//            multiplicative-expression additive-expression-sequence
//            multiplicative-expression
//
// additive-expression-sequence
//           additive-operator multiplicative-expression additive-expression-sequence
//           additive-operator multiplicative-expression
//
// additive-operator
//           one-of  + - 
//            
// multiplicative-expression
//            unary-expression multiplicative-expression-sequence
//            unary-expression
//
// multiplicative-expression-sequence
//            multiplicative-operator unary-expression multiplicative-expression-sequence
//            multiplicative-operator unary-expression
//
// multiplicative-operator
//           one-of  * / 
//
// unary-expression
//            unary-operator unary-expression
//            primary-expression
//            
// unary-operator
//            one of  ! + - 
//
// primary-expression
//            built-in-function
//            identifier ( function-call-argument-list )
//            identifier [ expression ]
//            identifier
//            integer-constant
//            character-constant
//            ( expression )
//
// function-call-argument-list
//            function-call-argument , function-call-argument-list
//            function-call-argument
//
// function-call-argument
//            string-literal
//            pointer-identifier
//            expression
//
// built-in-function
//           fgetc ( stdin )
//           fputc ( expression , stdout)
//           fputc ( expression , stderr)
//           exit  ( expression )
//           debug ( expression )


// ---------------------------------------------------------------------------
// built-in-function
//           fgetc ( stdin )
//           fputc ( expression , stdout)
//           fputc ( expression , stderr)
//           exit  ( expression )
//           debug ( expression )
//
syntax_built_in_function() {

    // ----- fgetc  ( stdin )
    //
    if (token_advance_if("fgetc")) {
        if (! (token_advance_if("(") && token_advance_if("stdin") && token_advance_if(")"))) {
            error_syntax("fgetc(stdin) expected");
        }

        compiler_built_in_function_fgetc();
        return True;
    }

    // ----- fputc ( expression , stdout)
    // ----- fputc ( expression , stderr)
    //
    if (token_advance_if("fputc")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after fputc");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after fputc opening parenthesis");
        }

        if (! token_advance_if(",")) {
            error_syntax("fputc takes two arguments");
        }

        if (token_advance_if("stdout")) {
            compiler_built_in_function_fputc_stdout();
        }
        else if (token_advance_if("stderr")) {
            compiler_built_in_function_fputc_stderr();
        }
        else {
            error_syntax("second argument of fputc must be stdout or stderr");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }   
            
        return True;
    }

    // ----- exit ( expression )
    //
    if (token_advance_if("exit")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after exit");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after exit opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }

        compiler_built_in_function_exit();
        return True;
    }

    // ----- debug ( expression )
    //
    if (token_advance_if("debug")) {

        if (! token_advance_if("(")) {
            error_syntax("opening parenthesis expected after debug");
        }

        if (! syntax_expression()) {
            error_syntax("expression expected after debug opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected");
        }

        compiler_built_in_function_debug();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// function-call-argument
//            string-literal
//            pointer-identifier
//            expression
//
syntax_function_call_argument() {

    if (token_type_is(Token_t_string_literal)) {
        compiler_function_call_string_literal_argument(token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }
    
    // need to check symbol table to determine if identifier needs to be passed as a pointer
    if (token_type_is(Token_t_identifier) && (! token_lookahead_text_is("["))) {
        if (compiler_function_call_pointer_argument(token_text)) { // >>>>>>>>>>
            token_advance();
            return True;
        }
    }

    if (syntax_expression()) {
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// function-call-argument-list
//            function-call-argument , function-call-argument-list
//            function-call-argument
//
syntax_function_call_argument_list(int argument_no, int function_argument_count[]) {
    int cookie[1];

    if (! syntax_function_call_argument()) {
        return False;
    }

    function_argument_count[0] = function_argument_count[0] + 1;

    compiler_function_call_argument_prepare(cookie); // >>>>>>>>>>

    if (token_advance_if(",")) {
        syntax_function_call_argument_list(argument_no + 1, function_argument_count);
    }

    compiler_function_call_argument_pass(argument_no + 1, function_argument_count[0], cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// primary-expression
//            built-in-function
//            identifier ( function-call-argument-list )
//            identifier [ expression ]
//            identifier
//            integer-constant
//            character-constant
//            ( expression )
//
syntax_primary_expression() {
    char cookie[Str_size];
    char name[Str_size];
    int function_argument_count[1];

    // ------ built-in-function

    if (syntax_built_in_function()) {
        return True;
    }

    // ------ identifier ( function-call-argument-list )

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) {
        copy(name, token_text);
        token_advance();
        token_advance();

        compiler_function_call_prepare(name, cookie); // >>>>>>>>>>

        function_argument_count[0] = 0;
        syntax_function_call_argument_list(0, function_argument_count);

        compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                
        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected after function call expression");
        }

        return True;
    }

    // ------ identifier [ expression ]

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
        copy(name, token_text);
        token_advance();
        token_advance();

        if (! syntax_expression()) {
            error_syntax("expression expected after opening bracket");
        }

        if (! token_advance_if("]")) {
            error_syntax("closing bracket expected");
        }

        compiler_primary_expression_array_index(); // >>>>>>>>>>
        compiler_primary_expression_identifier(name); // >>>>>>>>>>
        return True;
    }

    // ------ identifier

    if (token_type_is(Token_t_identifier)) {
        compiler_primary_expression_identifier(token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }

    // ------ integer-constant

    if (token_type_is(Token_t_integer_constant)) {
        compiler_primary_expression_integer_constant(token_text); // >>>>>>>>>>       
        token_advance();
        return True;
    }

    // ----- character-constant

    if (token_type_is(Token_t_character_constant)) {
        compiler_primary_expression_character_constant(token_text[0]); // >>>>>>>>>>        
        token_advance();
        return True;
    }

    // ------ ( expression )

    if (token_advance_if("(")) {
        if (! syntax_expression()) {
            error_syntax("expression expected after opening parenthesis");
        }

        if (! token_advance_if(")")) {
            error_syntax("closing parenthesis expected after expression");
        }

        return True;
    }

    return False;
}



// ---------------------------------------------------------------------------
// unary-operator
//            one of  ! + - 
//
syntax_unary_operator(char s[]) {
 
    return contains(" ! + - ", s);
}

// ---------------------------------------------------------------------------
// unary-expression
//            unary-operator unary-expression
//            primary-expression
//            
syntax_unary_expression() {
    char operator_text[Str_size];

    if (token_type_is(Token_t_symbol) && syntax_unary_operator(token_text)) {
        copy(operator_text, token_text);
        token_advance();

        if (! syntax_unary_expression()) {
            error_syntax("expression expected after unary operator");
        }
                  
        compiler_unary_expression(operator_text); // >>>>>>>>>>
        return True;
    }

    return syntax_primary_expression();
}

// ---------------------------------------------------------------------------
// multiplicative-operator
//           one-of  * / 
//
syntax_multiplicative_operator(char s[]) {
 
    return contains(" * / ", s);
}

// ---------------------------------------------------------------------------
// multiplicative-expression-sequence
//            multiplicative-operator unary-expression multiplicative-expression-sequence
//            multiplicative-operator unary-expression
//
syntax_multiplicative_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_multiplicative_operator(token_text))) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_multiplicative_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_unary_expression()) {
        error_syntax("expression expected after unary operator");
    }

    compiler_multiplicative_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_multiplicative_expression_sequence();

    return True;
}


// ---------------------------------------------------------------------------
// multiplicative-expression
//            unary-expression multiplicative-expression-sequence
//            unary-expression
//
syntax_multiplicative_expression() {

    if (! syntax_unary_expression()) {
        return False;
    }

    syntax_multiplicative_expression_sequence();
    
    return True;
}

// ---------------------------------------------------------------------------
// additive-operator
//           one-of  + - 
//            
syntax_additive_operator(char s[]) {

    return contains(" + - ", s);
}

// ---------------------------------------------------------------------------
// additive-expression-sequence
//           additive-operator multiplicative-expression additive-expression-sequence
//           additive-operator multiplicative-expression
//
syntax_additive_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_additive_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_additive_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_multiplicative_expression()) {
        error_syntax("expression expected right of additive operator");
    }

    compiler_additive_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_additive_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// additive-expression
//            multiplicative-expression additive-expression-sequence
//            multiplicative-expression
//
syntax_additive_expression() {

    if (! syntax_multiplicative_expression()) {
        return False;
    }

    syntax_additive_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// relational-operator
//           one-of < <= > >=
//
syntax_relational_operator(char s[]) {

    return contains(" < <= > >= ", s);
}

// ---------------------------------------------------------------------------
// relational-expression-sequence
//            relational-operator additive-expression relational-expression-sequence
//            relational-operator additive-expression
//
syntax_relational_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_relational_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_additive_expression()) {
        error_syntax("expression expected right of relational operator");
    }

    compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_relational_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// relational-expression
//            additive-expression relational-expression-sequence
//            additive-expression
//
syntax_relational_expression() {
 
    if (! syntax_additive_expression()) {
        return False;
    }

    syntax_relational_expression_sequence();

    return True;
}


// ---------------------------------------------------------------------------
// equality-operator
//            one-of == !=
//
syntax_equality_operator(char s[]) {

    return contains(" == != ", s);
}

// ---------------------------------------------------------------------------
// equality-expression-sequence
//            equality-operator-operator relational-expression equality-expression-sequence
//            equality-operator-operator relational-expression
//
syntax_equality_expression_sequence() {
    int cookie;
    char operator_text[Str_size];

    if (! (token_type_is(Token_t_symbol) && syntax_equality_operator(token_text)) ) {
        return False;
    }

    copy(operator_text, token_text);
    token_advance();

    cookie = compiler_relational_or_equality_expression_sequence_begin(); // >>>>>>>>>>

    if (! syntax_relational_expression()) {
        error_syntax("expression expected right of equality operator");
    }

    compiler_relational_or_equality_expression_sequence_end(operator_text, cookie); // >>>>>>>>>>

    syntax_equality_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// equality-expression
//            relational-expression equality-expression-sequence
//            relational-expression
//
syntax_equality_expression() {

    if (! syntax_relational_expression() ) {
        return False;
    }

    syntax_equality_expression_sequence();

    return True;
}

// ---------------------------------------------------------------------------
// logical-and-switch-sequence
//            && equality-expression logical-and-switch-sequence
//            && equality-expression
//
//
syntax_logical_and_switch_sequence(char cookie[]) {

    if (! token_advance_if("&&")) {
        return False;
    }

    if (! syntax_equality_expression()) {
        error_syntax("expression expected right of logical and");
    }

    compiler_logical_and_switch_sequence(cookie); // >>>>>>>>>>

    syntax_logical_and_switch_sequence(cookie);

    return True;
}

// ---------------------------------------------------------------------------
// logical-and-expression
//            equality-expression logical-and-switch-sequence
//            equality-expression
//
syntax_logical_and_expression() {
    char cookie[Str_size];

    if (! syntax_equality_expression() ) {
        return False;
    }
    
    if (token_text_is("&&")) {
        compiler_logical_and_expression_begin(cookie); // >>>>>>>>>>

        syntax_logical_and_switch_sequence(cookie);

        compiler_logical_and_expression_end(cookie); // >>>>>>>>>>
    }

    return True;
}


// ---------------------------------------------------------------------------
// logical-or-switch-sequence
//            || logical-and-expression logical-or-switch-sequence
//            || logical-and-expression
//
syntax_logical_or_switch_sequence(char cookie[]) {

    if (! token_advance_if("||")) {
        return False;
    }

    if (! syntax_logical_and_expression()) {
        error_syntax("expression expected right of logical-or operator");
    }

    compiler_logical_or_switch_sequence(cookie); // >>>>>>>>>>

    syntax_logical_or_switch_sequence(cookie);

    return True;
}

// ---------------------------------------------------------------------------
// logical-or-expression
//            logical-and-expression logical-or-switch-sequence
//            logical-and-expression
//
syntax_logical_or_expression() {
    char cookie[Str_size];
 
    if (! syntax_logical_and_expression()) {
        return False;
    }
    
    if (token_text_is("||")) {
        compiler_logical_or_expression_begin(cookie); // >>>>>>>>>>

        syntax_logical_or_switch_sequence(cookie);

        compiler_logical_or_expression_end(cookie); // >>>>>>>>>>
    }

    return True;
}

// ---------------------------------------------------------------------------
// expression
//            logical-or-expression
//
syntax_expression() {

    return syntax_logical_or_expression();
}


// ---------------------------------------------------------------------------
// function-call-statement
//            built-in-function
//            identifier ( function-call-argument-list )
//
syntax_function_call_statement() {
    char cookie[Str_size];
    char function_name[Str_size];
    int function_argument_count[1];

    if (syntax_built_in_function()) {
        return True;
    }

    if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
        return False;
    }

    copy(function_name, token_text);

    token_advance();
    token_advance();

    compiler_function_call_prepare(function_name, cookie); // >>>>>>>>>>

    syntax_function_call_argument_list(0, function_argument_count);

    compiler_function_call_execute(cookie, function_argument_count[0]); // >>>>>>>>>>
                
    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after function call");
    }

    return True;
}

// ---------------------------------------------------------------------------
// return-statement
//            return expression
//            return
//
syntax_return_statement() {
 
    if (! token_advance_if("return")) {
        return False;
    }

    syntax_expression();

    compiler_return_statement(); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// expression-statement
//           expression
//
syntax_expression_statement() {

    return syntax_expression();
}

// ---------------------------------------------------------------------------
// assignment-statement
//            identifier = expression
//            identifier [ expression ] = expression
//            
syntax_assignment_statement() {
    int cookie[1];
    char variable_name[Str_size];

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("=")) {
        copy(variable_name, token_text);
        token_advance();
        token_advance();
   
        if (! syntax_expression()) {
            error_syntax("expression expected after equal sign");
        }

        compiler_assignment_statement(variable_name); // >>>>>>>>>>

        return True;
    }

    if (token_type_is(Token_t_identifier) && token_lookahead_text_is("[")) {
        copy(variable_name, token_text);
        token_advance();
        token_advance();

        if (! syntax_expression()) {
            error_syntax("expression expected within array index");
        }

        if (! token_advance_if("]")) {
            error_syntax("closing bracket expected after array index");
        }
            
        if (! token_advance_if("=")) {
            error_syntax("equal sign expected after array index");
        }

        compiler_assignment_statement_array_begin(cookie); // >>>>>>>>>>
   
        if (! syntax_expression()) {
            error_syntax("expression expected after equal sign");
        }

        compiler_assignment_statement_array_end(cookie); // >>>>>>>>>>
        compiler_assignment_statement(variable_name); // >>>>>>>>>>

        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// while-statement
//            while ( expression ) statement
//
syntax_while_statement() {
    char cookie[Str_size];

    if (! token_advance_if("while") ) {
        return False;
    }

    if (! token_advance_if("(") ) {
        error_syntax("opening parenthesis expected after while keyword");
    }

    compiler_while_statement_begin(cookie); // >>>>>>>>>>

    if (! syntax_expression()) {
        error_syntax("expression expected in while statement");
    }

    compiler_while_statement_test(cookie); // >>>>>>>>>>

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after while statement");
    }

    if (! syntax_statement() ) {
        error_syntax("statement expected after while");
    }

    compiler_while_statement_end(cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// if-statement
//            if ( expression ) statement else statement
//            if ( expression ) statement
//
syntax_if_statement() {
    char cookie[Str_size];

    if (! token_advance_if("if") ) {
        return False;
    }

    if (! token_advance_if("(") ) {
        error_syntax("opening parenthesis expected after if keyword");
    }

    if (! syntax_expression()) {
        error_syntax("expression expected in if statement");
    }

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after if statement");
    }

    compiler_if_statement_test_fn(cookie); // >>>>>>>>>>

    if (! syntax_statement() ) {
        error_syntax("statement expected after if");
    }

    if (! token_advance_if("else") ) {
         compiler_if_statement_no_else_fn(cookie); // >>>>>>>>>>
         return True;
    }

    compiler_if_statement_else_fn(cookie); // >>>>>>>>>>

    if (! syntax_statement() ) {
        error_syntax("statement expected after else");
    }

    compiler_if_statement_else_end_fn(cookie); // >>>>>>>>>>

    return True;
}

// ---------------------------------------------------------------------------
// enumerator
//            identifier = integer-constant
//            identifier
//
syntax_enumerator() {
    char constant_name[Str_size];

    if (! token_type_is(Token_t_identifier) ) {
        return False;
    }
    
    copy(constant_name, token_text);
    token_advance();

    if (token_text_is("=")) {
        token_advance();

        if (! token_type_is(Token_t_integer_constant) ) {
            error_syntax("integer constant expected after equal sign in enum declaration");
        }

        compiler_enumerator_assigned_value(constant_name, token_text); // >>>>>>>>>>
        token_advance();
        return True;
    }

    compiler_enumerator(constant_name); // >>>>>>>>>>
    return True;
}



// ---------------------------------------------------------------------------
// enumerator-list
//            enumerator , enumerator-list
//            enumerator
//            
syntax_enumerator_list() {
    if (! syntax_enumerator() ) {
        return False;
    }

    if (token_advance_if(",")) {

        if (! syntax_enumerator_list() ) {
            error_syntax("identifier expected after comma in enum declaration");
        }
    }

    compiler_enumerator_list_end(); // >>>>>>>>>>

    return True;
}


// ---------------------------------------------------------------------------
// type-specifier
//            int
//            char
//
syntax_type_specifier() {

    if (token_text_is("int") || token_text_is("char")) {
        token_advance();
        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// declaration
//            type-specifier identifier ;
//            type-specifier identifier [ integer-constant ] ;
//            type-specifier identifier [ identifier ] ;
//            enum { enumerator-list } ;
//
syntax_declaration() {
    char variable_name[Str_size];
    char array_length[Str_size];

    if (syntax_type_specifier()) {
    
        if (! token_type_is(Token_t_identifier)) {
            error_syntax("identifier expected after type specifier in declaration");
        }

        copy(variable_name, token_text);
        token_advance();

        // simple type declaration -------------------------------------------
        if (! token_text_is("[")) {
            compiler_declaration_integer(variable_name); // >>>>>>>>>>

            if (! token_advance_if(";") ) {
                error_syntax("semicolon expected after declaration");
            }

            return True;
        }

        // array type declaration -------------------------------------------
        copy(array_length, token_lookahead_text);

        if (token_lookahead_type_is(Token_t_integer_constant)) {
            compiler_declaration_integer_array_constant_length_specifier(variable_name, array_length); // >>>>>>>>>>
        }
        else if (token_lookahead_type_is(Token_t_identifier)) {
            compiler_declaration_integer_array_identifier_length_specifier(variable_name, array_length); // >>>>>>>>>>
        }
        else {
            error_syntax("identifier or integer constant expected after opening bracket in array declaration");
        }

        token_advance();
        token_advance();

        if (! token_advance_if("]") ) {
            error_syntax("closing bracket expected in array declaration");
        }

        if (!token_advance_if(";")) {
            error_syntax("semicolon expected after array declaration");
        }

        return True;

    }

    // enum declaration ------------------------------------------------------
    if (token_advance_if("enum")) {

        if (! token_advance_if("{")) {
            error_syntax("opening brace expected after enum keyword");
        }

        if (! syntax_enumerator_list() ) {
            error_syntax("enumerator list expected");
        }

        if (! token_advance_if("}")) {
            error_syntax("closing brace expected after enumerator list");
        }

        if (! token_advance_if(";")) {
            error_syntax("semicolon expected after enumerator declaration"); // ????
        }

        return True;
    }

    return False;
}

// ---------------------------------------------------------------------------
// local-declaration-list
//            declaration local-declaration-list
//            declaration
//
syntax_local_declaration_list() {
    if (! syntax_declaration() ) {
        return False;
    }

    syntax_local_declaration_list();

    return True;
}

// ---------------------------------------------------------------------------
// compound-statement
//            { statement-list } 
//
syntax_compound_statement() {

    if (! token_advance_if("{") ) {
        return False;
    }

    syntax_statement_list();

    if (! token_advance_if("}") ) {
        error_syntax("closing brace expected at end of compound statement");
    }

    return True;
}

// ---------------------------------------------------------------------------
// statement
//           if-statement
//           while-statement
//           compound-statement
//           assignment-statement ;
//           expression-statement ;
//           return-statement ;
//
syntax_statement() {

    compiler_output_source_as_comment(); // >>>>>>>>>>

    if (syntax_if_statement() || 
        syntax_while_statement() ||
        syntax_compound_statement() ) {

        return True;
    }

    if (syntax_assignment_statement() ||
        syntax_expression_statement() ||
        syntax_return_statement() ) {

        if (! token_advance_if(";") ) {
            error_syntax("semicolon expected after statement");
        }

        return True;
    }

    return False;
}


// ---------------------------------------------------------------------------
// statement-list
//            statement statement-list
//            statement
//            
syntax_statement_list() {

    if (! syntax_statement() ) {
        return False;
    }

    syntax_statement_list();
    return True;
}

// ---------------------------------------------------------------------------
// function-argument-declaration
//            type-specifier identifier
//            type-specifier identifier []
//
syntax_function_argument_declaration(int argument_no) {
    int argument_type;
    char argument_name[Str_size];

    if (! syntax_type_specifier() ) {
        return False;
    }

    if (! token_type_is(Token_t_identifier) ) {
        error_syntax("identifier expected after type specifier in function definition");
    }

    copy(argument_name, token_text);
    token_advance();

    if (token_advance_if("[")) {
        argument_type = Compiler_t_integer_pointer;

        if (! token_advance_if("]") ) {
            error_syntax("closing bracket expected after array argument declaration");
        }
    } else {
        argument_type = Compiler_t_integer;
    }

    compiler_function_argument_declaration_item(argument_name, argument_type, argument_no + 1); // >>>>>>>>>>
    return True;
}

// ---------------------------------------------------------------------------
// function-argument-declaration-list
//            function-argument-declaration , function-argument-declaration-list
//            function-argument-declaration
//
syntax_function_argument_declaration_list(int argument_no) {

    if (! syntax_function_argument_declaration(argument_no) ) {
        return False;
    }

    if (! token_advance_if(",") ) {
        return True;
    }

    if (! syntax_function_argument_declaration_list(argument_no + 1) ) {
        error_syntax("function argument expected");
    }

    return True;
}

// ---------------------------------------------------------------------------
// function-compound-statement
//            { local-declaration-list statement-list } 
//            { statement-list } 
//
syntax_function_compound_statement() {
    
    if (! token_advance_if("{") ) {
        return False;
    }

    syntax_local_declaration_list();

    compiler_function_compound_statement_locals_declared(); // >>>>>>>>>>

    syntax_statement_list();

    if (! token_advance_if("}") ) {
        error_syntax("closing brace expected at end of function");
    }

    return True;
}

// ---------------------------------------------------------------------------
// function-definition
//            identifier( function-argument-declaration-list ) function-compound-statement
//            identifier( ) function-compound-statement
//
syntax_function_definition() {
    char function_name[Str_size];

    if (! (token_type_is(Token_t_identifier) && token_lookahead_text_is("(")) ) {
        return False;
    }

    copy(function_name, token_text);
    token_advance();
    token_advance();

    compiler_output_source_as_comment(); // >>>>>>>>>>

    compiler_function_definition_begin(function_name); // >>>>>>>>>>

    syntax_function_argument_declaration_list(0);

    if (! token_advance_if(")") ) {
        error_syntax("closing parenthesis expected after function definintion");
    }

    if (! syntax_function_compound_statement() ) {
        error_syntax("function body expected after function definintion");
    }

    compiler_function_definition_end(); // >>>>>>>>>>

    return True;
}


// ---------------------------------------------------------------------------
// global-declaration
//            declaration
//            function-definition
//
syntax_global_declaration() {

    if (syntax_declaration()) {
        return True;
    }

    if (syntax_function_definition()) {
        return True;
    }

    return False;
}
// ---------------------------------------------------------------------------
// global-declaration-list
//            global-declaration global-declaration-list
//            global-declaration
//
syntax_global_declaration_list() {

    if (! syntax_global_declaration()) {
        return False;
    }

    syntax_global_declaration_list();
    return True;
}

// ---------------------------------------------------------------------------
// program
//            global-declaration-list
//
syntax_program() {
    token_advance();

    compiler_program_begin(); // >>>>>>>>>>

    if (! syntax_global_declaration_list()) {
        error_syntax("function or variable declaration expected");
    }

    if (! token_type_is(Token_t_eof)) {
        error_syntax("end of file expected");
    }

    compiler_output_source_as_comment();
    compiler_program_end(); // >>>>>>>>>>

    return True;
}

#ifndef _MSC_VER
#line 2 "bminus.c"
#endif

#ifdef _MSC_VER
#include "builtinfuncs_ansic.h"
#include "globals.h"
#include "stringlib.h" 
#include "errormessages.h"
#include "preprocessor.h" 
#include "token.h" 
// #include "target_cvirtualmachine.h" 
#include "target_javascript.h" 
// #include "target_linuxassemblerx86.h" 
#include "compiler.h" 
#include "syntax.h" 
#endif


main() {
    preprocessor_init();
    token_init();
    compiler_init();
    target_init();

    syntax_program();

    exit(0);

}

