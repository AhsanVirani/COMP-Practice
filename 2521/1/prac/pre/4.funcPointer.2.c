#include <stdio.h>

int square(int);

int
main(void)
{

	int a;
	scanf("%d", &a);
	
	printf("%d is the square", square(a));

	return 0;

}

int 
square(int a)	{ return (a * a); }
