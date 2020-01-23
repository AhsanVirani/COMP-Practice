#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <assert.h> 

#include "linked_list.h"


typedef struct _node {
	Item	data;
	node	next;	node	prev;
} _node;


node 
new_node(void)
{
	node n = malloc(sizeof(*n));
	assert(n != NULL);

	n->data = NULL;
	n->next = NULL;	n->prev = NULL;
	
	return n;

}

void 
set_data(node n, Item d)
{
	assert(n != NULL && d != NULL);
	n->data = item_clone(d);
}

Item
get_data(node n)
{
	assert(n != NULL);
	return n->data;
}

void
set_next(node src, node dest)
{
	assert(src != NULL && dest != NULL);
	src->next = dest;
}

node
get_next(node n)
{
	assert(n != NULL);
	return n->next;
}

void
set_prev(node src, node dest)
{
	assert(src != NULL && dest != NULL);
	src->prev = dest;
}

node
get_prev(node n)
{
	assert(n != NULL);
	return n->prev;
}

static
void
list_free_recursive(node n)
{
	if(n->next == NULL)
	{
		free(n); 
		return;
	} else {
		list_free_recursive((*n).next);
		free(n);
		return;
	}
}

void
linkedListDestroy(node n)
{
	printf("Destroying Linked List...\n");
	list_free_recursive(n);
}


