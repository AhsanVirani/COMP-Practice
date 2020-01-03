#include <stdio.h>
#include <stdlib.h>

// Struct definition with typedef
typedef char *Item;
typedef struct _node *node;
typedef struct _node{

	Item data;
	node next;

} _node;


node
create_node()
{
	node n = malloc(sizeof((*n)));
	if(n == NULL)
	{
		fprintf(stderr, "No memory to allocate\n");
		exit(EXIT_FAILURE);

	}
	
	(*n).data = NULL;	
	(*n).next = NULL;

	return n;

}

void
show_reverse(node n)
{

	if((*n).next == NULL)
	{
		printf("%s ", (*n).data);

	}

	else{
		show_reverse((*n).next);
		printf("%s ", (*n).data);
	
	}	


}

void
free_list(node n)
{

	if((*n).next == NULL)
	{
		free(n);
	}
	
	else{

		free_list((*n).next);
		free(n);

	}

}


int
main(void)
{

	node n1 = malloc(sizeof((*n1)));
	node n2 = malloc(sizeof((*n2))); //

	if(n1 == NULL)	
	{	
		fprintf(stderr, "No memory to allocate\n");
		exit(EXIT_FAILURE);
	}

	(*n1).data = NULL; (*n1).next = NULL;
	(*n1).data = "HELLO";

	if(n2 == NULL)	//
	{	
		fprintf(stderr, "No memory to allocate\n"); //
		exit(EXIT_FAILURE); //
	}

	(*n2).data = NULL; (*n2).next = NULL; //
	(*n2).data = "GANDU";

	printf("%s %s\n", (*n1).data, (*n2).data);


	(*n1).next = n2;
	printf("%s %s\n", (*n1).data, (*(*n1).next).data);

	node n3 = create_node();
	(*n2).next = n3;
	
	(*n3).data = "!!";		
	printf("%s %s%s\n", (*n1).data, (*n2).data, (*n3).data);

	node c = n1;
	while(c != NULL)
	{
		printf("%s ", (*c).data);
		c = (*c).next;

	}
	printf("\n");

	for(node d = n1; d != NULL; d = (*d).next)
	{
		printf("%s ", (*d).data);

	}
	printf("\n");

	show_reverse(n1);
	printf("\n");

	free_list(n1);

	return 0;

}
