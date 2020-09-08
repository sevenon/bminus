fn(char s1[], char s2[]) {
	int i;

	i = 0;
	while(s1[i] != 0) {
		fputc(s1[i], stdout);
		i = i + 1;
	}
	fputc(' ', stdout);

	i = 0;
	while(s2[i] != 0) {
		fputc(s2[i], stdout);
		i = i + 1;
	}
	fputc('\n', stdout);

	exit(0);
	debug(0);
}

main() {

	fn("hello", "world");
}
