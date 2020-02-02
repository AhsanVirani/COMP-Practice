#include <stdio.h>

#include "item.h"

#ifndef PRAC__NODE_H 
#define PRAC__NODE_H

typedef struct _node *node;

node
create_node(void);

void
set_name(node n, Item name);

Item
get_name(node n);


void
destroy_name(node n);

void
destroy_node(node n);

void
set_data(node n, void *data);

void *
get_data(node n);

void
destroy_data(node n);

void
set_next(node n, node next);

node
get_next(node n);

void
set_prev(node n, node prev);

node
get_prev(node n);

// inserting m after n 	n->m
void
insert_after(node n, node m);

// inserting m before n	m->n
void
insert_before(node n, node m);

void
show_node(node n);

int
white_test(void);

#endif

