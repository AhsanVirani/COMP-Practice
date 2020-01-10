#include <stdio.h>
#include <assert.h>

#include "stack.h"


typedef struct stack{
	Item	data;
	Stack	next;
} stack;

size_t
stack_size(Stack s)
{
	size_t count = 0;
	//if (s->n == NULL) return 0;
	for(Stack c = s; c != NULL; c = c->next)
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
	(*s).data = 0, (*s).next = NULL;
	return s;
}

void 
stack_drop (Stack s)
{
	if(s == NULL)	return;
	else if(s->next == NULL)
	{
		free(s); return;

	}
	else{
		stack_drop(s->next);
		free(s); return;
	}
}

Item 
stack_pop (Stack s)
{
	assert(s != NULL);
	//Stack head = s;
	if ( s->next == NULL)
	{
		Item rtn = s->data;
		free(s); s->next = NULL;
		return rtn;
	}
	Stack curr = s, prev = s;
	while(curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	Item rtn = curr->data;
	free(curr); curr = NULL; prev->next = NULL;
	return rtn;
}

void 
stack_push (Stack s, Item data)
{
	Stack a = stack_new();
	a->data = data;
	//stack is empty, create a new node and save the address in stack n
	if(s == NULL)	s = a;
	// 5, list of 5. node -> 5, 
	else{
		Stack curr = s;
		while(curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = a;
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
	a->data = 1; 
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



