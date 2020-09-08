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

