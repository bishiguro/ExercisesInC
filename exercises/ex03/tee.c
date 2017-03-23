/*
A command that reads from stdin and writes to both stdout and another file
Author: Bonnie Ishiguro
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

/* 
tee [OPTION] ... [FILE] ...

-a: appends to the given file
FILE: the file to write or append text to

*/

int main(int argc, char *argv[]) {
	char mode[2] = "w"; // default file access mode is write

	char ch;
	while ((ch = getopt(argc, argv, "a")) != EOF) {
		switch (ch) {
		case 'a':
			strcpy(mode, "a"); // changes file access mode to append
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

	fscanf(stdin, "%[^\n]", input); // read from stdin

	fprintf(fp, "%s\n", input); // print from input to the file
	fprintf(stdout, "%s\n", input); // print from input to stdout
	fclose(fp);
}

/* 
3) Reflect: what worked, what slowed you down?  What would you do
differently next time?

The smaller details slowed me down the most, such as figuring out how to allow 
scanf to accept text with spaces, how to modify the "mode" string, and the 
correct placement of lines 26-27.  Overall, however, the HeadFirst C textbook 
was a good guide for helping me understand using files and accepting command 
line arguments/options.

4) Compare your solution to the real thing.  What do you see in
professional code that is not in your solution?

The professional code allows for more than one file, which I did not include.
It also includes error-checking for opening files.

*/