// this is a comment

fn(char arr[]) {
	int i;

	i = 0;
	while(arr[i] != 0) {
		debug(arr[i]);
		i = i + 1;
	}
}

main() {// more comments
	int i;
	i = 5;
	fn("hello // hello");
	// comment
	debug(i);
}
