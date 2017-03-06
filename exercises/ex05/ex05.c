#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int two_comp() {
	char bits[8] = "";
	signed int val = 12;

	// put individual bits in char array
	int i;
	for (i=0; i<sizeof(val); i=i+1) {
		int bit = (val >> i) & 1;
		bits[i] = bit;
	}

	signed int res = 12^15; // 1100^1111
	res = res + 1; 
	fprintf(stdout, "%i\n", res); 
	return 1;

	// TODO: how to display has neg int rather than pos equivalent?
}

void lower_to_upper() {
	// char word[] = "hello";
	// int bit = ((word >> 6) & 1) ^ 1;
	// printf("%i\n", bit);
}

int main() { 
	two_comp();
	lower_to_upper();
}
