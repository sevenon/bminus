int glob;

main() {
	int i;

	i = 0;
	glob = -5;

	while (1) {
		debug(i);
		if (i < glob) {
			return;
		}
		i = i - 1;
	}
}