#include <stdio.h>


int
operation(int (*operator)(int, int), int a, int b)
{
	return operator(a, b);
}

int
add(int a, int b) { return a + b; }

int
multiply(int a, int b)
{
	int r = 0;
	for (int i = 0; i < a; i++)
	{
		r = operation(&add, r, b);
	}
	return r;
}

int
mod(int a, int b)
{
	return a % b; 
}

int
main(void)
{
	int a = 5, b = 3;
	// human(makeCoffee, cup);
	// human(makeTea, cup);
	printf("add %d\n", operation(&add, a, b));

	printf("mod %d\n", operation(&mod, a, b));

	printf("mult %d\n", operation(&multiply, a, b));


	return 0;
}

