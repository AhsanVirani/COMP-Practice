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

	stack_push (new, 5);
	stack_push (new, 6);
	printf("%d\n", stack_pop(new));
	
	return EXIT_SUCCESS;
	
	
}
