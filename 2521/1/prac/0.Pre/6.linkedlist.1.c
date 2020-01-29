#include <stdio.h>
#include <stdlib.h>

struct node {
	int		data;
	struct node *	next;
};

int
main(void)
{

	struct node *n1 = malloc(sizeof(struct node));
	struct node *n2 = malloc(sizeof(*n2)); // shortcut using the definition itself

	(*n1).data = 5; 	(*n1).next = n2;
	(*n2).data = 10; 	(*n2).next = NULL;
	printf("n1 stores the address %p\n", n1);
	printf("n2 stores the address %p\n", n2);

	struct node *curr = n1;
	while(curr != NULL)
	{

		printf("%d at address %p\n",(*curr).data, curr);
		curr = (*curr).next;

	}
	
	free(n1); free(n2); n1 = NULL; n2 = NULL;


	return 0;

}
