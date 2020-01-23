#include <stdio.h>
#include <stdlib.h>

#include "item.h"
#include "queue.h"

int 
main(void)
{
	Queue q = queue_new();
	queue_push(q, "AHSAN");
	queue_push(q, "<3");
	queue_push(q, "CHONGI");
	
	printf("Size is %ld\n", queue_size(q));
	Item i1 = queue_pop(q);
	Item i2 = queue_pop(q);
	Item i3 = queue_pop(q);
	printf("%s removed\n", i1);
	printf("%s removed\n", i2);
	printf("%s removed\n", i3);
	item_drop(i1);
	item_drop(i2);
	item_drop(i3);
	queue_destroy(q);

	return EXIT_SUCCESS;
}
