#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twoscomp(int val) {
    return (val ^ -1) + 1;
}

void upper(char *str) {
    for (int i=0; i < strlen(str); i++) {
        str[i] = str[i] ^ 32;
    }
}

int main (int argc, char *argv[])
{
    int val = twoscomp(12);
    printf("Two's Comp of 12: %i\n", val);

    char str[] = "chocolate";
    upper(str);
    printf("Upper: %s\n", str);
}
