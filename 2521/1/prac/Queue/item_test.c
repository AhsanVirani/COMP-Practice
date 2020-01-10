#include <stdio.h>
#include "item.h"


int
main(void)
{
	Item testing = "Hello";
	Item testing_1 = item_clone(testing);
	
	printf("%s", testing_1);
	printf("\n");

	item_free(testing_1);
	
	return 0;
}
