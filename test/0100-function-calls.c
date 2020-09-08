int global1;

f1(int arg1, int arg2, int arg3) {
	debug(arg1);
	debug(arg2);
	debug(arg3);
}

int global2;

f2(int arg2, int arg3) {
	return arg2 * arg3;
}

int global3;

main() {
	int local1;

	f1(10, f2(10,50), 30);

	local1 = 10;
	global1 = 1;
	global2 = 2;
	global3 = 3;

	debug(local1);
	debug(global1);
	debug(global2);
	debug(global3);
}
