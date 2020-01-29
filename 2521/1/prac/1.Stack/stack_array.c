#include <assert.h>
#include <err.h>
#include <stdlib.h>
#include <sysexits.h>

#include "stack.h"
#define MAX_SIZE 10

typedef struct stack stack;

struct stack {
	Item items[MAX_SIZE];
	size_t n_items;

};

/** Create a new, empty Stack. */
stack *
stack_new (void)
{
	stack *new = malloc(sizeof(*(new))); 
	if(new == NULL)	err (EX_OSERR, "Couldn't allocate stack");
	(*new) = (stack) { .items = {}, .n_items = 0 };

//	stack test;
//	test.items = {};
//	test.n_items = 0;
	
	return new;

}

/** Destroy a stack. */
void 
stack_drop (stack *s) { free(s); }

/** Remove an item from the top of a stack */
Item 
stack_pop (stack *s)
{
	assert(s != NULL);
	assert((*s).n_items > 0);
	Item it = (*s).items[(*s).n_items - 1];
	(*s).n_items--;

	return it;

}



/** add an item to the top of a stack. */
void 
stack_push (stack *s, Item it)
{
	assert (s != NULL);
	assert ((*s).n_items < MAX_SIZE - 1);
	(*s).items[(*s).n_items] = it;
	(*s).n_items++; 

}

/** Get the number of items in a stack. */
size_t 
stack_size (stack *s)
{
	assert (s != NULL);
	return (*s).n_items;

}


