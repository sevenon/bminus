
enum { False = 0, True = 1 };

// ---------------------------------------------------------------------------
write(char str[]) {
	int i;

	i = 0;
	while(str[i] != 0) {
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
strequals(char str1[], char str2[]) {
	int i;

	i = 0;
	while(str1[i] == str2[i]) {
		if(str1[i] == 0 && str2[i] == 0)
			return True;
		
		if(str1[i] == 0 || str2[i] == 0)
			return False;

		i = i + 1;
	}

	return False;
}

// ---------------------------------------------------------------------------
copy(char dest[], char src[]) {
	int i;

	i = 0;
	while(src[i] != 0) {
		dest[i] = src[i];

		i = i + 1;
	}

	dest[i] = 0;
}

// ---------------------------------------------------------------------------
append(char dest[], char src[]) {
	int i;
	int j;

	i = 0;
	while(dest[i] != 0) {
		i = i + 1;
	}

	j = 0;
	while(src[j] != 0) {
		dest[i] = src[j];

		i = i + 1;
		j = j + 1;
	}

	dest[i] = 0;
}

// ---------------------------------------------------------------------------
append_char(char dest[], int c) {
	int i;

	i = 0;
	while(dest[i] != 0) {
		i = i + 1;
	}

	dest[i] = c;
	dest[i + 1] = 0;
}

// ---------------------------------------------------------------------------
contains(char str[], char substr[]) {
	int i;
	int j;
	int k;

	if(substr[0] == 0)
		return True;

	i = 0;
	while (str[i] != 0) {
		j = i;
		k = 0;
		while(str[j] == substr[k]) {
			j = j + 1;
			k = k + 1;

			if(substr[k] == 0)
				return True;
		}

		i = i + 1;
	}

	return False;
}

// ---------------------------------------------------------------------------
contains_char(char str[], int c) {
	int i;

	i = 0;
	while (str[i] != 0) {
		if (str[i] == c)
			return True;

		i = i + 1;
	}

	return False;
}

// ---------------------------------------------------------------------------
length(char str[]) {
	int i;

	i = 0;
	while (str[i] != 0)
		i = i + 1;

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
	int i;
	int j;
	int n_mod_10;
	char tmp_swap;

	i = 0;
	while(i == 0 || n != 0) {
		n_mod_10 = n - (10 * ( n / 10));
		str[i] = '0' + n_mod_10;
		n = n / 10;

		i = i + 1;
	}

	str[i] = 0;

	i = i - 1;
	j = 0;
	while(j < i) {
		tmp_swap = str[i];
		str[i] = str[j];
		str[j] = tmp_swap;
		i = i - 1;
		j = j + 1;
	}
}

// ---------------------------------------------------------------------------


main() {
	char str[256];

	debug(strequals("hello", "world"));
	debug(strequals("", "world"));
	debug(strequals("hello", ""));
	debug(strequals("", ""));
	debug(strequals("hello", "hello1"));
	debug(strequals("hello", "hello"));

	copy(str, "");
	writeln(str);
	copy(str, "Hello");
	writeln(str);
	copy(str, "world");
	writeln(str);

	str[0] = 0;
	append(str, "");
	write(str); write("\n");
	append(str, "Hello");
	write(str); write("\n");
	append(str, " ");
	write(str); write("\n");
	append(str, "world");
	write(str); write("\n");

	str[0] = 0;
	append_char(str, '!');
	append(str, "Hello world");
	append_char(str, '!');
	writeln(str); write("\n");

	debug(contains("", ""));
	debug(contains("", "abcd"));
	debug(contains("abcd", ""));
	debug(contains("a", ""));
	debug(contains("", "b"));
	debug(contains("abcdef", "ab"));
	debug(contains("abcdef", "ef"));
	debug(contains("abcdef", "cd"));
	debug(contains("abcdef", "abcx"));
	debug(contains("abcdef", "efx"));
	debug(contains("ab", "abcd"));
	debug(contains("cd", "abcd"));
	debug(contains("cd", "cd"));

	writeln("");
	debug(contains_char("", 0));
	debug(contains_char("", 'a'));
	debug(contains_char("a", 0));
	debug(contains_char("a", 'a'));
	debug(contains_char("abc", 'a'));
	debug(contains_char("abc", 'c'));
	debug(contains_char("abc", 'd'));

	writeln("");
	debug(length(""));
	debug(length("a"));
	debug(length("abc\n"));

	writeln("");
	debug(str_to_int(""));
	debug(str_to_int("0"));
	debug(str_to_int("12345"));
	debug(str_to_int("012345"));
	debug(str_to_int("0123450"));
	debug(str_to_int("2147483647"));
	debug(str_to_int("abc"));

	writeln("");
	int_to_str(100, str); writeln(str);
	int_to_str(0, str); writeln(str);
	int_to_str(-10, str); writeln(str);
	int_to_str(-0, str); writeln(str);
	int_to_str(10, str); writeln(str);
	int_to_str(9292, str); writeln(str);
	int_to_str(131, str); writeln(str);
	int_to_str(2147483647, str); writeln(str);
}
