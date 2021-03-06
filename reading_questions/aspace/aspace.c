/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void print_local()
{
	int local = 10;
	printf ("Address of local is %p\n", &local);
}

int main ()
{
    int local = 5;
    void *p = malloc(10);
    void *q = malloc(10);

    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local is %p\n", &local);
    printf ("Address of p is %p\n", p);
    printf ("Address of q is %p\n", q);

    print_local();
    
    return 0;
}
