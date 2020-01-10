#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "linked_list.h"

typedef struct _node {
	Item	data;
	node	next;
} _node;


void
set_data(node n, Item data)
{
	assert(n!=NULL);
	n->data = data;
}

void
set_next(node n, node m)
{
	assert(n!=NULL);
	n->next = m;
}


node
get_next(node n)
{
	assert(n!=NULL);
	return n->next;
}

Item
get_data(node n)
{
	assert(n!=NULL);
	return n->data;
}

bool
is_next_null(node n)
{
	if (n != NULL && n->next == NULL) return true;
	return false;
}

node
makeNode(void)
{
	node n = (node)malloc(sizeof(*n));
	(*n).data = 0;
	(*n).next = NULL;

	return n;
}

void
setNodeItem(node n, Item data)
{
	(*n).data = data;	
}
void
setNodeNext(node n, node m)
{
	(*n).next = m;	
}

node
makeNode_1(void)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, 0);
	setNodeNext(n, NULL);

	return n;
}

node
makeSetDataNode(Item data)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, data);
	setNodeNext(n, NULL);
	
	return n;
}

node
makeSetNextNode(node m)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, 0);
	setNodeNext(n, m);

	return n;
}

node
makeSetDataNextNode(Item data, node m)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, data);
	setNodeNext(n, m);

	return n;
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

/**
static
int 
whitebox_test(void)
{
	node head = malloc(sizeof(*head));
	(*head).data = 5;
	(*head).next = NULL;

	head = makeSetDataNextNode(4, head);

	printf("%d\n", (*head).data);
	printf("%d\n", (*(*head).next).data);

	linkedListDestroy(head);

	//free((*head).next);
	//(*head).next = NULL;
	//free(head);
	head = NULL;

	return EXIT_SUCCESS;

} **/

/**
int main(void)
{
	if (whitebox_test() == 0){
		printf("passed\n");
	}
	return EXIT_SUCCESS;
}
**/


