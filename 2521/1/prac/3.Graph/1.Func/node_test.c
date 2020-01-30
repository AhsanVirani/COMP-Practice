#include <stdio.h>

#include "node.h"


int
main(void)
{
	node cities = create_node();
	set_name(cities, "Karachi");
	set_next(cities, create_node());
	set_name(get_next(cities), "Islamabad");
	set_next(get_next(cities), create_node());
	set_name(get_next(get_next(cities)), "Rawalpindi");
	set_next(get_next(get_next(cities)), NULL);
/**
	node karachi = create_node();
	karachi->name = "Gulshan";
	karachi->next = create_node();
	karachi->next->name = "Jouhar";
	karachi->next->next = create_node();
	karachi->next->next->name = "Liyari";
	karachi->next->next->next = NULL;

	node islamabad = create_node();
	islamabad->name = "Defence";
	islamabad->next = create_node();
	islamabad->next->name = "F-Sector";
	islamabad->next->next = create_node();
	islamabad->next->next->name = "G-Sector";
	islamabad->next->next->next = NULL;

	node rawalpindi = create_node();
	rawalpindi->name = "R1";
	rawalpindi->next = create_node();
	rawalpindi->next->name = "R2";
	rawalpindi->next->next = NULL;

	cities->data = karachi;
	cities->next->data = islamabad;
	cities->next->next->data = rawalpindi;
**/

	for(node curr = cities; curr != NULL; curr = get_next(curr))
	{
		printf("Welcome to %s city\n", get_name(curr));
		//for(node ncurr = curr->data; ncurr != NULL; ncurr = ncurr->next)
			//printf("Your suburb is %s\n", ncurr->name);
	}
	for(node curr = cities; curr != NULL; curr = get_next(curr))
	{
		//printf("Welcome to %s city\n", get_name(curr));
		destroy_node (curr);
		//for(node ncurr = curr->data; ncurr != NULL; ncurr = ncurr->next)
			//printf("Your suburb is %s\n", ncurr->name);
	}

	return EXIT_SUCCESS;
}
