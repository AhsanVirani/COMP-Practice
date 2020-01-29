#include <stdio.h>
#include <stdbool.h>
#include "item.h"


int
main(void)
{
	printf("Running Black tests xD...\n");
	Item t = "Hello";
	Item t_2 = "Hellu";
	Item t_1 = item_clone(t);
	
	//printf("%s", testing_1);
	//printf("\n");

	item_show(t_1);

	printf("%d\n", item_eq (t, t_1));
	printf("%d\n", item_eq (t, t_2));

	printf("testing item_eq\n");
	if ( 1 == item_eq (t, t_1)) {printf("\ttest 1 passed");}

	printf("%ld %ld\n", item_len(t), item_size(t));

	printf("black tests done XD...\n");




	item_drop(t_1);
	
	return 0;
}
