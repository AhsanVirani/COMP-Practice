#include <stdio.h>
#include <stdlib.h>


typedef int Item;

typedef struct _node *node;
typedef struct _node {
	Item	data;
	node	next;
} _node;

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
}

node
makeSetNextNode(node m)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, 0);
	setNodeNext(n, m);
}

node
makeSetDataNextNode(Item data, node m)
{
	node n = (node)malloc(sizeof(*n));
	setNodeItem(n, data);
	setNodeNext(n, m);
}



int 
main(void)
{
	node head = malloc(sizeof(*head));
	(*head).data = 5;
	(*head).next = NULL;

	head = makeSetDataNextNode(4, head);

	printf("%d\n", (*head).data);
	printf("%d\n", (*(*head).next).data);

	free((*head).next);
	(*head).next = NULL;
	free(head);
	head = NULL;

	return EXIT_SUCCESS;

}
