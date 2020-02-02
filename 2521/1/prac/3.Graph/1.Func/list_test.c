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
	add_node(l, n2);
	printf("list size %d\n", get_size(l));
	show_list(l);
	destroy_list(l);

	return EXIT_SUCCESS;
}
