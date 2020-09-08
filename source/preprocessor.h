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

