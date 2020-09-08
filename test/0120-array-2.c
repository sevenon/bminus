
main() {
	int i;
	int arr[10];

	i = 9;
	while (i >= 0) {
		arr[i] = i + 100;
		i = i - 1;
	}
	i = 9;
	while (i >= 0) {
		arr[i] = i + 100;
		i = i - 1;
	}

	i = 0;
	while (i < 10) {
		debug(arr[i]);
		i = i + 1;
	}	
}
