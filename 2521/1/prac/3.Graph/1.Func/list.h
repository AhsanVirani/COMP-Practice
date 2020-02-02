#include <stdio.h>

#include "item.h"
#include "node.h"

#ifndef PRAC__LIST_H
#define PRAC__LIST_H

typedef struct _list *list;


list
create_list();

void
destroy_list(list l);

void
set_head(list l, node n);

node
get_head(list l);

void
set_tail(list l, node n);

node
get_tail(list l);

size_t
get_size(list l);

void
add_node(list l, node n);

node
make_node(Item name, void *data);

void
insert_node(list l, size_t pos, node n);

void
show_list(list l);

#endif
