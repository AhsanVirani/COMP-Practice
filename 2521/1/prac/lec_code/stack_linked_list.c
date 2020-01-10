#include <stdio.h>
#include <assert.h>

#include "linked_list.h"
#include "stack.h"

typedef struct stack{
	node	n;
} stack;

size_t
stack_size(Stack s)
{
	size_t count = 0;
	//if (s->n == NULL) return 0;
	for(node c = s->n; c != NULL; c = get_next(c))
	{
		count++;

	}
	return count;
}

/** Create a new, empty stack. */
Stack stack_new (void)
{
	Stack s = malloc(sizeof((*s)));
	if(s == NULL)
	{
		fprintf(stderr, "No Memory");
	}
	(*s).n = NULL;
	return s;
}

void 
stack_drop (Stack s)
{
	if (s->n !=NULL) linkedListDestroy((*s).n);
	free(s);
}

Item 
stack_pop (Stack s)
{
	assert(s->n != NULL);
	node head = (*s).n;
	if ( is_next_null(head) == true)
	{
		Item rtn = get_data(head);
		free(head); s->n = NULL;
		return rtn;
	}
	node curr = s->n, prev = s->n;
	while(get_next(curr) != NULL)
	{
		prev = curr;
		curr = get_next(curr);
	}
	Item rtn = get_data(curr);
	free(curr); curr = NULL; set_next(prev, NULL);
	return rtn;
}

void 
stack_push (Stack s, Item data)
{
	node a = makeNode();
	set_data(a, data);
	//stack is empty, create a new node and save the address in stack n
	if(s->n == NULL)	s->n = a;
	// 5, list of 5. node -> 5, 
	else{
		node curr = s->n;
		while(get_next(curr) != NULL)
		{
			curr = get_next(curr);
		}
		set_next(curr, a);
	}
		
}

Stack 
stack_stacks (Stack s1, Stack s2)
{
	// Create a new temporary stack.
	Stack s3 = stack_new();

	// Put the items of s1 into the new temporary s3. Reverse order add
	while(stack_size(s1) != 0)
	{
		Item t = stack_pop(s1);
		//printf("%d\n", t);
		stack_push(s3, t);	
	}

	// Put it at end of s2 in right order
	while(stack_size(s3) != 0)
	{
		Item t1 = stack_pop(s3);
		//printf("%d\n", t1);
		stack_push(s2, t1);
	}

	// Get rid of the temporary stack
	//stack_drop(s3);
	return s2;
}

/**
int 
main(void)
{
	Stack new = stack_new();
	if(new->n == NULL)
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

**/

