int g1;
int g2;

main() {
	int i;
	int j;
	int k;


	i = 0;
	j = 10;
	k = -5;


	g1 = 2;


	g1 = 1 == 10 == 10;
	debug(g1);

	g1 = 10 == 10 == 1;
	debug(g1);

	g1 = 1 > 5 != 0;
	debug(g1);

	g1 = 1 > 5 == 0;
	debug(g1);

	debug(2 < 5);
	debug(2 <= 5);
	debug(2 <= 2);
	debug(2 > 5);
	debug(2 >= 5);
	debug(2 >= 2);
	debug(2 == 2);
	debug(2 == 3);
	debug(3 == 2);
	debug(2 != 2);
	debug(2 != 3);
	debug(3 != 2);

}