#include <stdio.h>


typedef char Item;

typedef struct node *link;
typedef struct node {
	Item	item;
	link	next;
} node;


int 
list_length (link l)
{
	link curr = NULL; curr = l;
	
	int length = 0;
	while(curr != NULL)
	{
		length++;
		curr = (*curr).next;

	}
	
	return length;

}

int 
list_length_recursive (link l)	
{
	if(l == NULL)
	{
		return 0;
	} else if ((*l).next == NULL) {
	
		return 1;
	} else {
	
		//list_length_recursive((*l).next)
		return 1 + list_length_recursive((*l).next);

	}	

}

int 
list_length_recursive_short (link l)
{
	return l == NULL ? 0 : 1 + list_length_recursive_short ((*l).next);
}
/**
c->next nthing
return 0
c
return 1 + 0
b
return 1 + (1 + 0)
a
return 1 + (1 + (1+0) ) = 3	
**/

int 
main(void)
{
	
	node n1 = (node) { .item = 'a', .next = NULL };
	node n2 = (node) { .item = 'b', .next = NULL };
	node n3 = (node) { .item = 'c', .next = NULL };
	
	n1.next = &n2; n2.next = &n3;
	printf("%d\n", list_length_recursive_short(&n1));

	return 0;
}
