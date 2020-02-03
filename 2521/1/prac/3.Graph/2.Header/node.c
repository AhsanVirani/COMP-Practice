#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "item.h"
#include "node.h"

typedef struct _node {
	Item	name;	void	*data;
	node	next;	node	prev;
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
destroy_node(node n)
{
	assert(n != NULL);
	if (n->name != NULL)
		destroy_name(n);
	if (n->data != NULL)
		destroy_data(n);
	free(n);
}

void
set_name(node n, Item name)
{
	assert(n != NULL);
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
	assert(n != NULL);
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
	if (next != NULL)
		set_prev(next, n);
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

void
insert_after(node n, node m)
{
	assert(n != NULL && m != NULL);
	if(n->next == NULL)	set_next(n, m);
	else
	{
		set_next(m, get_next(n));
		set_next(n, m);
	}
}

void
insert_before(node n, node m)
{
	assert(n != NULL && m != NULL);
	if(get_prev(n) == NULL)	set_next(m, n);
	else
	{
		set_next(get_prev(n), m);
		set_next(m, n);
	}
}

void
show_node(node n)
{
	assert(n != NULL);
	printf("Node: %p\n\tItem: ", n);
	if(n->name != NULL)	item_show(n->name);
	printf("\n\tData: %p\n", n->data);
	printf("\tPrev: %p\n\tNext: %p\n", n->prev, n->next);
	
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
	node tmp1=cities;
	node tmp2=cities->data;
	for(node curr = cities; curr != NULL; curr = tmp1)
	{
		//printf("Welcome to %s city\n", curr->name);
		for(node ncurr = curr->data; ncurr != NULL; ncurr = tmp2)
		{
			tmp2=ncurr->next;
			free (ncurr);//printf("Your suburb is %s\n", ncurr->name);
		}
		tmp1=curr->next;
		free (curr);
	}



	return EXIT_SUCCESS;
}

