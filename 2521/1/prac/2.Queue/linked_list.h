#include <stdio.h>
#include <stdlib.h>

#include "item.h"


#ifndef PRAC__LINKED_LIST_H_
#define PRAC__LINKED_LIST_H_

typedef struct _node *node;


node 
new_node(void);

void 
set_data(node n, Item d);

Item
get_data(node n);

void
set_next(node src, node dest);

node
get_next(node n);

void
set_prev(node src, node dest);

node
get_prev(node n);



void
linkedListDestroy(node n);



#endif 
