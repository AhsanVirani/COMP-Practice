#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"


typedef struct _list {
    size_t  size;
    node    head;
    node    tail;
} _list;

list
create_list()
{
	list l = malloc(sizeof(*l));
	assert(l != NULL);
	l->size = 0;
	l->head = NULL;	l->tail = NULL;
	
	return l;	
}

static void
_destroy_nodes(node n)
{
	if(n == NULL)	return;
	else
	{
		_destroy_nodes(get_next(n));
		destroy_node(n);
	}
}

void
destroy_list(list l)
{
	assert(l != NULL);
	if (l->size > 0) _destroy_nodes(l->head);
	l->head = NULL; l->tail = NULL;
	l->size = 0;
	free(l);
}

void
set_head(list l, node n)
{
	assert(l != NULL);
	if(l->head == NULL)	l->tail = n;
	l->head = n;
}

node
get_head(list l)
{
	assert(l != NULL);	
	return l->head;
}

void
set_tail(list l, node n)
{
	assert(l != NULL);
	if(l->head == NULL)	l->head = n;
	l->tail = n;
}

node
get_tail(list l)
{
	assert(l != NULL);	
	return l->head;
}

size_t
get_size(list l)
{
	assert(l != NULL);
	return l->size;
}

node
make_node(Item name, void *data)
{
	node n = create_node();
	set_name(n, name);
	set_data(n, data);

	return n;
}

void
add_node(list l, node n)
{
	assert(l != NULL && n != NULL);
	if(l->tail == NULL)
	{
		l->head = n;	l->tail = l->head;
	} else
	{
		set_next(l->tail, n);	
	}	
	l->size++;
}

void
insert_node(list l, size_t pos, node n)	
{
	assert(l != NULL && n != NULL);
	// Insert at head
	if(l->size == 0)	set_head(l, n);

	else if((double)(pos/l->size)*100.0 <= 50.0) // list a b c d add at pos 2 which is b.
	{
		node curr = l->head;
		for(int i = 1; i < pos; i++)	curr = get_next(curr);
		insert_after(curr, n);

	} else // list a b c d add at pos 3 which is b.
	{ 
		node curr = l->tail;
		for(int i = l->size; i >= pos; i--)			curr = get_prev(curr);
		insert_before(curr, n);
	}

	l->size++;
}

void
show_list(list l)
{
	assert(l != NULL);
	for(node curr = l->head; curr != NULL; curr = get_next(curr))	show_node(curr);
}





