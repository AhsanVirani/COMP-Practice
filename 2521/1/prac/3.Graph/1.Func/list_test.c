#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "node.h"

int 
main(void)
{
	list l = create_list();
	node n = make_node("corona", NULL);
	//add_node(l, n);
	node n1 = make_node("virus", NULL);
	//add_node(l, n1);
	node n2 = make_node("kills", NULL);
	//add_node(l, n2);
	node n_i = make_node("CHONGI", NULL);
	insert_node(l, 1, n_i);
	insert_node(l, 1, n2);
	insert_node(l, 3, n1);
	insert_node(l, 2, n);

	node n4 = make_node("testing", NULL);
	insert_node(l, 2, n4);


	show_list(l);
	destroy_list(l);

	return EXIT_SUCCESS;
}
