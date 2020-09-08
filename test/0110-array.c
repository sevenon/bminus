enum { arrlen = 10 };

int j[10];
int k[arrlen];

fn() {
	return 2;
}

main() {
	enum { five = 5 };
	int b;
	int i[five];

	i[fn()] = 4;

	j[i[2]] = 99;

	b = 4;

	k[arrlen-1] = 0;

	debug(j[b]);
}
