#include <stdio.h>
#include <stdlib.h>

// Struct definition with typedef
typedef char *Item;
typedef struct _node *node;
typedef struct _node{

	Item data;
	node next;

} _node;


int
main(void)
{

	node n1 = malloc(sizeof((*n1)));
	if(n1 == NULL)	
	{	
		fprintf(stderr, "No memory to allocate\n");
		exit(EXIT_FAILURE);
	}

	(*n1).data = NULL; (*n1).next = NULL;
	// char a[5] = {'h', 'e', 'l', 'l', 'o', '\0'}; <==> 
	char *a = "hello";

	putchar(*(a+2)); putchar(a[0]); putchar(*(a+0));
	(*n1).data = "HELLO";
	printf("%c\n", *((*n1).data+2));
	
		

	return 0;

}
