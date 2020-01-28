#include <stdio.h>
#include <assert.h>

#include "stack.h"

typedef struct list *node;
typedef struct list{
	Item	data;
	List	next;
} list;

typedef struct stack{
	List n;
} stack;

size_t
stack_size(Stack s)
{
	size_t count = 0;
	//if (s->n == NULL) return 0;
	for(node c = s->n; c != NULL; c = c->next)
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


Stack 
stack_stacks (Stack s1, Stack s2)
{
	// Create a new temporary stack.
	Stack s3 = stack_new();

	// Put the items of s1 into the new temporary s3. Reverse order add
	while(stack_size(s1) != 0)
	{
		stack_push(s3, stack_pop(s1));	
	}

	// Put it at end of s2 in right order
	while(stack_size(s3) != 0)
	{
		stack_push(s2, stack_pop(s3));
	}

	// Get rid of the temporary stack
	stack_drop(s3);
	return s2;
}


int
main(void)
{

	Stack a = stack_new();
	stack_push(a, 1); 
	Stack b = stack_new();
	b->data = 2;
	Stack c = stack_new();
	c->data = 3;
	Stack d = stack_new();
	d->data = 4;
	
	b->next = c; c->next = d;
	Stack e = stack_stacks(a, b);
	printf("%d", e->data);
	while(e != NULL)
	{
		printf("%d\n", e->data);
		e = e->next;
	}

	return 0;
}



