#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "node.h"

int 
main(void)
{
	list l = create_list();
	node n = make_node("corona", NULL);
	add_node(l, n);
	node n1 = make_node("virus", NULL);
	add_node(l, n1);
	node n2 = make_node("kills", NULL);
	node n_i = make_node("CHONGI", NULL);
	insert_node(l, 2, n_i);
	add_node(l, n2);
	show_list(l);
	destroy_list(l);

	return EXIT_SUCCESS;
}
