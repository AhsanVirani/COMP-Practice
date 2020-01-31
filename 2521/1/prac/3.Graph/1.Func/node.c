#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

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

int
main(void)
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
	for(node curr = cities; curr != NULL; curr = curr->next)
	{
		//printf("Welcome to %s city\n", curr->name);
		for(node ncurr = curr->data; ncurr != NULL; ncurr = ncurr->next)
			free (ncurr);//printf("Your suburb is %s\n", ncurr->name);
		free (curr);
	}
	// INSERT AFTER TEST
	node test = create_node();
	set_name(test, "hello");
	node test_l = create_node();
	set_next(test, test_l);
	set_name(get_next(test), "world");
	node test_insert = create_node();
	set_name(test_insert, " ");
	insert_after(test, test_insert);
	//forward test insert after
	for(node curr = test; curr != NULL; curr = get_next(curr))
	{
		printf("%s\n", get_name(curr));
	}
	//backward test insert after
	for(node curr = test_l; curr != NULL; curr = get_prev(curr))
	{
		printf("%s\n", get_name(curr));
	}
	for(node curr = test_l; curr != NULL; curr = get_prev(curr))
	{
		destroy_node(curr);
	}
	// INSERT BEFORE test
	node b_test = create_node();
	set_name(b_test, "hello");
	node b_test_l = create_node();
	set_next(b_test, b_test_l);
	set_name(get_next(b_test), "world");
	node b_test_insert = create_node();
	set_name(b_test_insert, " ");
	insert_before(b_test_l, b_test_insert);
	//forward test insert after
	for(node curr = b_test; curr != NULL; curr = get_next(curr))
	{
		printf("%s\n", get_name(curr));
	}
	//backward test insert after
	for(node curr = b_test_l; curr != NULL; curr = get_prev(curr))
	{
		printf("%s\n", get_name(curr));
	}
	for(node curr = b_test_l; curr != NULL; curr = get_prev(curr))
	{
		destroy_node(curr);
	}


	return EXIT_SUCCESS;
}
