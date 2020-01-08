#include <stdio.h>
#include <stdlib.h>

typedef char Item;

typedef struct node *link;
typedef struct node {
	Item	item;
	link	next;
} node;


link
new_node()
{
	link h = malloc(sizeof((*h)));
	if(h == NULL)
	{
		fprintf(stderr, "No memory");

	}
	(*h).item = '\0';	(*h).next = NULL;
	return h;

}

link list_duplicate_recursive (link l)
{

	if(l == NULL)	return NULL;

	else if ((*l).next == NULL){
	
		link n = new_node();
		(*n).item = (*l).item;
		return n;

	} else{

		link n = new_node();
		(*n).item = (*l).item;
		(*n).next = list_duplicate_recursive ((*l).next);
		
		return n;

	}
	/**
	a, b
	n.item = a 	a->next = b node which we cr
  ---------------
	h.item = b	b->next = c 
 --------------------------
	x.item c  c->next = null
	**/
  
}

void
free_nodes_recursive (link n)
{
	if(n == NULL)	return;
	else if(n->next == NULL)	{free(n); return;}
	else{
		free_nodes_recursive (n->next);
		free(n);	return;

	}
/**
a, b, c
now at c
c->next = NULL ->  free(c) return;
now at b
free(b) -> return;
now at a
free(a) -> return;
Now gone to main function from where it was called
**/

}
/*
Item
insert_item(link n, )
{



}
*/

link
list_duplicate (link l)
{
	link l_d = NULL, curr = l, curr_d = NULL;

	while(curr != NULL)
	{
		if(l_d == NULL) {
			l_d = new_node();
			l_d->item = curr->item;
			curr_d = l_d;
		} else {
			curr_d->next = new_node();
			curr_d = curr_d->next;
			curr_d->item = curr->item;
		}
		curr = curr->next;
	};

	return l_d;
}

int 
main(void)
{
	node n1 = (node) { .item = 'a', .next = NULL };
	node n2 = (node) { .item = 'b', .next = NULL };
	node n3 = (node) { .item = 'c', .next = NULL };
	
	n1.next = &n2; n2.next = &n3;
	
	link n1_c = list_duplicate(&n1);
	for(link curr = n1_c; curr != NULL; curr = curr->next)
	{
		printf("%c\n", curr->item);

	}

	free_nodes_recursive (n1_c);

	return 0;
}
