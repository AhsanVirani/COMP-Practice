#include <stdio.h>

#include "stack.h"


int 
main(void)
{
	Stack new = stack_new();
	if(stack_size(new) == 0)
	{
		printf("Test 1 passed\n");
	}
	else{
		printf("Test 1 failed\n");
	}

	stack_push (new, 6);
	stack_push (new, 5);
	Stack n = stack_new();
	stack_push(n, 10);
	stack_push(n, 9);
	stack_push(n, 8);

	Stack catch = stack_stacks(new, n);	
	while(stack_size(catch) != 0)
	{
		printf("%d\n", stack_pop(catch));

	}

	//printf("%d\n", stack_pop(new));
	
	return EXIT_SUCCESS;
	
	
}
