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
	node tmp = cities;
	node curr = cities;
	while(curr != NULL)
	{
		curr = get_next(curr);
		destroy_node(tmp);
		tmp = curr;
	}
	tmp = NULL; curr = NULL;

	printf("1x\n");
	// INSERT AFTER TEST
	node test = create_node();
	set_name(test, "hello");
	node test_l = create_node();
	set_next(test, test_l);
	set_name(get_next(test), "world");
	node test_insert = create_node();
	set_name(test_insert, " ");
	insert_after(test, test_insert);
	//forward test insert after
	for(node curr = test; curr != NULL; curr = get_next(curr))
	{
		printf("%p->", curr);
		printf("%s\n", get_name(curr));
	}
	//backward test insert after
	for(node curr = test_l; curr != NULL; curr = get_prev(curr))
	{
		printf("%p->", curr);
		printf("%s\n", get_name(curr));
	}
	printf("test: %p\n", test);
	node i_tmp = test;
	node i_curr = test;
	printf("i_tmp: %p\n", i_tmp);

	while(i_curr != NULL)
	{
		i_curr = get_next(i_curr);
		printf("%p->", i_tmp);
		printf("%p->%s\n", i_tmp, get_name(i_tmp));
		destroy_node(i_tmp);
		i_tmp = i_curr;
	}
	i_tmp = NULL; i_curr = NULL;

	printf("2x\n");
	// INSERT BEFORE test
	node b_test = create_node();
	set_name(b_test, "hell");
	node b_test_l = create_node();
	set_next(b_test, b_test_l);
	set_name(get_next(b_test), "worl");
	node b_test_insert = create_node();
	set_name(b_test_insert, " -");
	insert_before(b_test_l, b_test_insert);
	//forward test insert after
	for(node curr = b_test; curr != NULL; curr = get_next(curr))
	{
		printf("%s\n", get_name(curr));
	}
	//backward test insert after
	for(node curr = b_test_l; curr != NULL; curr = get_prev(curr))
	{
		printf("%s\n", get_name(curr));
	}

	node d_tmp = b_test;
	node d_curr = b_test;
	while(d_curr != NULL)
	{
		d_curr = get_next(d_curr);
		printf("%p->%s\n", d_tmp, get_name(d_tmp));
		destroy_node(d_tmp);
		d_tmp = d_curr;
	}


	return EXIT_SUCCESS;
}
