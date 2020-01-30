#include <stdio.h>
#include <assert.h>

#include "node.h"

typedef struct _list *list;

typedef struct _list {
    size_t  size;
    node    head;
    node    tail;
} list;

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

void
add_node(list l, Item name, void *data)
{
	assert(l != NULL);
	node n = create_node();
	set_name(n, name);
	set_data(n, data);

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
insert_node(list l, node n)
{


}
