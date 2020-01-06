#include <stdio.h>

int square(int);

int
main(void)
{

	int a;
	scanf("%d", &a);
	
	int (*doSquare)(int) = &square;
	printf("%d is the square\n", doSquare(a));

	return 0;

}

int
square(int a)	{ return (a * a); }
