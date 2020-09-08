
main() {

    write("Hello world\n");
    exit(0);
}

write(char str[]) {
	int i;

	i = 0;
	while (str[i] != 0) {
		fputc(str[i], stdout);
		i = i + 1;
	}
}
