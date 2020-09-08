main() {
	int i;
	int t;

	i = 0;
	t = 100;

	while (i != 10) {
		if (i == 1)
			debug(i);
		else if (i == 2)
			debug(i);
		else if (i == 3)
			debug(i);
		else if (i == 4)
			debug(i);
		else if (i == 5)
			debug(i);
		else
			debug(t);

		i = i + 1;
	}

}
