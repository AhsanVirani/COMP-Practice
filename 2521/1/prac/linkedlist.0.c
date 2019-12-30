#include <stdio.h>
#include <stdlib.h>

struct grade {
	int	mark;
	char	performance;
};

int 
main(void)
{


	struct grade *s1 = (struct grade *)malloc(sizeof(struct grade));	//using malloc because the data type is not clear to C. int or char? 
	
	if(s1 == NULL)
	{
		fprintf(stderr, "Memory Full\n");
		exit(EXIT_FAILURE);
	}

	(*s1).mark = 75; (*s1).performance = 'D';
	printf("Mark for s1 = %d and performace = %c\n", (*s1).mark, (*s1).performance);
	
	free(s1); s1 = NULL;

	int a = 5;
	printf("%d\n", a);
	
	int *b = (int *)calloc(1, sizeof(int));
	if(b == NULL)
	{
		fprintf(stderr, "Out of Memory\n");
		exit(EXIT_FAILURE);
	}

	printf("auto initilised to %d\n", (*b));
	
	(*b) = 10;
	printf("Value set to %d\n", (*b));	

	free(b); b = NULL;

	return 0;

}





/*

|heap 	|
|c	|
|----	|
|	|
|-----	|
|	|
|______ |
|fnc1->b|
|_______|
|main->a|
|_______|

Stack for a.out program






*/
