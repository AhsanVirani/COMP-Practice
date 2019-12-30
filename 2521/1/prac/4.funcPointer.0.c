#include <stdio.h>


int square(int x) { return x * x; }

int add(int x, int y) { return x + y; }

int
main(void)
{
	int a = 5;
	int *ibox = &a;

	int (*sbox)(int);	// fbox is a pointer to a function that takes 1 parameter of type int and returns an int
	sbox = &square;

	int (*abox)(int, int);
	abox = &add;


	printf("square at %p took %d and returned -> %d\n", &square, a, square(a));	
	printf("%d\n", sbox(a));
	printf("%d is at address %p\n", a, ibox);
	printf("abox variable at %p stores pointer to function add at %p\n", &abox, *(&abox));
	printf("add at %p XX %p XX %p XX %p took %d %d and returned -> %d\n", &add, *(&abox), add, abox, a, a, abox(a, a) );	// A function is just an address in memory that stores the derivation you do. i.e. {return x + y}

	printf("printf is here in memory sea -> %p\n", printf);

	return 0;
}
