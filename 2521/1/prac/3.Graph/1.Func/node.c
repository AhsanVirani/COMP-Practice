#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "node.h"


typedef struct _node {
	Item	name;
	void	*data;
	node	next;
	node	prev;
} _node;

node
create_node(void)
{
	node new = (node)malloc(sizeof(*new));
	assert(new != NULL);
	new->name = NULL; new->data = NULL;
	new->next = NULL; new->prev = NULL;

	return new;
}

void
set_name(node n, Item name)
{
	assert(n != NULL && name != NULL);
	n->name = item_clone(name);
}

Item
get_name(node n)
{
	assert(n != NULL);
	return n->name;
}

void
destroy_name(node n)
{
	assert(n != NULL);
	item_drop(n->name);
}

// the data must be malloced
void
set_data(node n, void *data)
{
	assert(n != NULL && data != NULL);
	n->data = data;
}

void *
get_data(node n)
{
	assert(n != NULL);
	return n->data;
}

void
destroy_data(node n)
{	
	assert(n != NULL);
	free(n->data);
}

void
set_next(node n, node next)
{
	assert(n != NULL);
	n->next = next;
}

node
get_next(node n)
{
	assert(n != NULL);
	return n->next;
}

void
set_prev(node n, node prev)
{
	assert(n != NULL);
	n->prev = prev;
}

node
get_prev(node n)
{
	assert(n != NULL);
	return n->prev;
}

int
white_test(void)
{
	node cities = (node)malloc(sizeof(*cities));
	cities->name = "Karachi";
	cities->next = (node)malloc(sizeof(*cities));
	cities->next->name = "Islamabad";
	cities->next->next = (node)malloc(sizeof(*cities));
	cities->next->next->name = "Rawalpindi";
	cities->next->next->next = NULL;

	node karachi = (node)malloc(sizeof(*karachi));
	karachi->name = "Gulshan";
	karachi->next = (node)malloc(sizeof(*karachi));
	karachi->next->name = "Jouhar";
	karachi->next->next = (node)malloc(sizeof(*karachi));
	karachi->next->next->name = "Liyari";
	karachi->next->next->next = NULL;

	node islamabad = (node)malloc(sizeof(*islamabad));
	islamabad->name = "Defence";
	islamabad->next = (node)malloc(sizeof(*islamabad));
	islamabad->next->name = "F-Sector";
	islamabad->next->next = (node)malloc(sizeof(*islamabad));
	islamabad->next->next->name = "G-Sector";
	islamabad->next->next->next = NULL;
	
	node rawalpindi = (node)malloc(sizeof(*rawalpindi));
	rawalpindi->name = "R1";
	rawalpindi->next = (node)malloc(sizeof(*rawalpindi));
	rawalpindi->next->name = "R2";
	rawalpindi->next->next = NULL;

	cities->data = karachi;
	cities->next->data = islamabad;
	cities->next->next->data = rawalpindi;

	for(node curr = cities; curr != NULL; curr = curr->next)
	{
		printf("Welcome to %s city\n", curr->name);
		for(node ncurr = curr->data; ncurr != NULL; ncurr = ncurr->next)
			printf("Your suburb is %s\n", ncurr->name);
	}

	return EXIT_SUCCESS;
}
