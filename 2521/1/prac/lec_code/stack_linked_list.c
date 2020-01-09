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
	linkedListDestroy((*s).n);
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

