int g1;
int g2;

main() {
	int i;
	int j;
	int k;

	g1 = 2;
	g2 = -4;

	i = 5;
	j = 6;

	debug(i < 5 && j == 6);
	if (i < 5 && j == 6)
		debug(1);
	else
		debug(2);

	debug(0 || 1 && 1 && 1);

	debug(1 || 0 && 1 && 1);

	if (1 || debug(10)) {}
	if (0 || debug(20)) {}
	if (1 && debug(30)) {}
	if (0 && debug(40)) {}
}

