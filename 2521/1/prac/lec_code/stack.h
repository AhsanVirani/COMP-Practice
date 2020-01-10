#include <stdlib.h>
#include "item.h"

#ifndef PRAC__STACK_H_
#define PRAC__STACK_H_

typedef struct stack *Stack;

/** Create a new, empty stack. */
Stack stack_new (void);

/** Destroy a stack, releasing all resources associated with it. */
void stack_drop (Stack);

/** Remove an item from the top of a stack. */
Item stack_pop (Stack);

/** Add an item to the top of a stack. */
void stack_push (Stack, Item);

/** Get the number of items in a stack. */
size_t stack_size (Stack);

Stack 
stack_stacks (Stack, Stack);

#endif // !defined(PRAC__STACK_H)
