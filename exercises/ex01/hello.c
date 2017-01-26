#include <stdio.h>

int main()
{
	int x = 5;
	int y = x + 1;
	printf("%i\n", y);
}

/*
11. movl $5, -4(%rbp)
12. The optimized assembly code (-O2) of the main function is shorter, 
	although I am confused about how it works, as I do not see a reference to the value 5.
13. The optimized code calls the "__printf_chk" function instead of "printf," 
	the first of which checks for a stack overflow before computing.
14. The non-optimized code assigns x to 5 and y to x+1, 
	while the optimized code appears to only assign y to 6 directly, 
	perhaps because it is the only variable referenced after its assignment.
*/