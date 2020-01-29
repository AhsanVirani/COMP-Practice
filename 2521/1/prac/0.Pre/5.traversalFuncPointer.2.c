#include <stdio.h>
#include <stdlib.h>


void 
traverse (size_t a, char *arr[], int (*f)(const char *))
{
	for(size_t i = 0; i < a; i++)	{ (*f) (arr[i]); }


}

void
show_array (char *arr, size_t len)
{
	puts ("[");
	traverse (len, arr, &puts);
	puts ("]");

}


int
main (void)
{

	/*char ***u;
	char **a_b; */
	char **a_c = malloc(sizeof(char *)*6);
	printf("a_c box is at %p\n", &a_c);
	for (int i = 0; i < 5; i++)
 	{		
		char *arr = calloc(5, sizeof(char));
		for (int j = 0; j < 4; j++)
		{
			arr[j] = 65 + i;
		}
		//a_c[i] = arr;
		*(a_c + i) = arr;
		//printf("%p has %s\n", arr, arr);
	}
	//pointer. *pointer to access blocks
	//char * a_c [,b,c,d,e,f]
	show_array(*(a_c))
	*(a_c + 6)= NULL; 
	for (int k = 0; *(a_c + k) != NULL; k++) {
		//printf("%p has %s\n", *(a_c + k), *(a_c + k));
		//printf("%p\n", *(a_c + k));

		printf("%d\n", k);
	}


	char **a_c is pointer of pointers to char. [pointera, pointerb, ... , pointerf]
	*(*a_c) = 'A';
	return 0;
}
