/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() { // returns an integer array (in the form of a pointer)
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}

/* Exercise 2

1. Creates an array of size 5 filled with the value 42.
   Creates an array of size 5 filled with the values 0-4.
   Prints each of the values of the first array (42 five times).

2. stack.c: In function ‘foo’:
   stack.c:22:12: warning: function returns address of local variable [-Wreturn-local-addr]
     return array;
            ^

Rather than returning the array itself, foo returns its address in memory.

3. ./stack
0x7fffc55f12b0
0x7fffc55f12b0
Segmentation fault (core dumped)

The array declared in foo is allocated in stack memory, which is temporary memory.  Once foo exists, all of its variables are popped off of the stack.  Therefore, when main functions attempts to print the pointer associated with this array (which is a null point since the array does not exist), a segfault occurs.

4. If the print statements in foo() and bar() are printed out, the pointers of the stack-allocated arrays are no longer printed, but a segfault still occurs.

*/