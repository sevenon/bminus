fn(char s1[], char s2[]) {
	int i;

	i = 0;
	while(s1[i] != 0) {
		debug(s1[i]);
		i = i + 1;
	}
	
	i = 0;
	while(s2[i] != 0) {
		debug(s2[i]);
		i = i + 1;
	}
}

main() {

	fn("hello", "world");
}
