/*
A command that reads from stdin and writes to both stdout and another file
Author: Bonnie Ishiguro
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char mode[1] = "w"; // the default file access mode is write

	char ch;
	while ((ch = getopt(argc, argv, "a")) != EOF) {
		switch (ch) {
		case 'a':
			strcpy(mode, "a"); // changes the file access mode to append
			break;
		default:
			fprintf(stderr, "Unknown option: '%s'\n", optarg);
			return 1;
		}
	}

	// skip past the options to the command-line arguments
	argc -= optind; 
	argv += optind;

	FILE *fp = fopen(argv[0], mode);
	char input[100];

	fscanf(stdin, "%[^\n]", input); // read from stdin and store the result in input

	fprintf(fp, "%s\n", input); // print from input to the newly-created file
	fprintf(stdout, "%s\n", input); // print from input to stdout (the  display)
}

/* 
3) Reflect: what worked, what slowed you down?  What would you do
differently next time?

4) Compare your solution to the real thing.  What do you see in
professional code that is not in your solution?
*/