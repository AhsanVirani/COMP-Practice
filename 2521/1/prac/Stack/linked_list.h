#include <stdio.h>
#include <stdlib.h>

#include "item.h"


#ifndef PRAC__LINKED_LIST_H_
#define PRAC__LINKED_LIST_H_

typedef struct _node *node;

void
set_data(node n, Item data);

void
set_next(node n, node m);

node
get_next(node n);

Item
get_data(node n);

node
makeNode(void);

void
setNodeItem(node n, Item data);

void
setNodeNext(node n, node m);

node
makeNode_1(void);

node
makeSetDataNode(Item data);


node
makeSetNextNode(node m);


node
makeSetDataNextNode(Item data, node m);

void
linkedListDestroy(node n);

bool
is_next_null(node n);



#endif // !defined(PRAC__STACK_H)
