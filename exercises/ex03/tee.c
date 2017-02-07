#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char mode[1] = "w";

	char ch;
	while ((ch = getopt(argc, argv, "a")) != EOF) {
		switch (ch) {
		case 'a':
			strcpy(mode, "a");
			break;
		default:
			fprintf(stderr, "Unknown option: '%s'\n", optarg);
			return 1;
		}
	}

	argc -= optind;
	argv += optind;

	FILE *fp = fopen(argv[0], mode);
	char input[100];

	fscanf(stdin, "%[^\n]", input);

	fprintf(fp, "%s\n", input);
	fprintf(stdout, "%s\n", input);
}