#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char Item;
typedef struct dnode *node;

struct dnode{
	Item	item;
	node	prev, next;
};

node
new_node()
{
	node n = malloc(sizeof(*n));
	assert(n != NULL);
	n->item = '\0'; n->next = NULL; n->prev = NULL;
}

node append(node list1, node list2)
{
	
	if(list1 == NULL)	return list2;
	node curr = list1;
	while(curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = list2;
	if(list2 != NULL)	list2->prev = curr;


	return list1;

}

void
free_node_recursive(node n)
{
	if(n == NULL)	return;
	else if (n->next == NULL)
	{
		free(n); return;
	}
	else{
		free_node_recursive(n->next);
		free(n); return;
	}

	

}


int
main(void)
{

	node n1 = new_node();
	n1->item = 'a'; n1->next = NULL; n1->prev = NULL;

	node n2 = new_node();
	n2->item = 'b'; n2->next = NULL; n2->prev = NULL;
	
	node n3 = append(n1, n2);

	node curr = n3;
	while(curr!= NULL)
	{
		printf("%c\n", curr->item);
		curr = curr->next;

	}

	free_node_recursive(n3);

	return 0;
}
