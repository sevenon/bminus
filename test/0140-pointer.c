int arr[10];

f(int arr[]) {
	debug(arr[5]);
	arr[8] = 88;
}

fn(int arg[]) {
	arg[1] = 20;
	arg[5] = 99;
	debug(arg[1]);
	debug(arg[5]);
	f(arg);
}

main() {

	arr[0] = 10;

	fn(arr);

	debug(arr[0]);
	debug(arr[1]);
	debug(arr[8]);
}
