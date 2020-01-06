#include <stdio.h>

void
foo(void *f, char a)
{
	switch(a)
	{
		case 'i': printf("%d", *(int *)f); break;
		case 'c': putchar(*(char *)f);break;
		case 's': puts((char *)f); break;

		default: printf("Not Found!\n");
	}
}

int 
main(void)
{
	int i = 7;
	char c = 65, c_1 = 'c';
	char *s = "hello";
	foo(&i, 'i');
	printf("\n");
	foo(&c, c_1);
	printf("\n");
	foo(s, 's');	

	return 0;
}
