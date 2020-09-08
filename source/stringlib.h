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
