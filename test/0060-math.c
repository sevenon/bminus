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

	k = 4 + 2 - 16 + 8 + (2 * 5 / 2);
	debug(k);

	k = (g1 + i * 5 / 2 - 10 + 4 / 2) * 2 - j * (g2 - 1);
	debug(k);

}