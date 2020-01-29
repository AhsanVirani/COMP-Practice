#include <stdio.h>
#include "stack.h"

int
main(int argc, char **argv)
{
	Stack s = stack_new();
	stack_push(s, 5);
	stack_push(s, 6);

	printf("%d\n", stack_pop(s));
	printf("%d\n", stack_pop(s));

	return 0;
}



