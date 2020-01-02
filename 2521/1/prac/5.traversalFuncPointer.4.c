#include <stdio.h>
#include <stdlib.h>

void
traverse(size_t b, char ** array1, int(*f)(const char *) )
{

	for(size_t i = 0; i < b; i++)
	{
		(*f) (array1[i]);
		
	}

}


void
show_array(size_t a, char **array) 
{
	puts ("[");
	traverse(a, array, &puts);
	puts("]");
}

int
main(void)
{
	
	char ** arr = malloc(sizeof(char *) * 5); // so arr is a pointer of pointers to characters meaning *(arr)[5] = {'','','','',''}
// char ** arr <==> char * arr[]

	for(int i = 0; i < 5; i++)
	{
		char * arr1 = calloc(5, sizeof(char)); //arr[5] = {'','','','','\0'}
		for(int j = 0; j < 4; j++)
		{
			arr1[j] = 65 + i;
			//putchar(*(arr1));
			
		}
		
		*(arr + i) = arr1; // arr[i] = arr1;
		
		
	}
	// char *arrx = arr[0] <==> *(arr + 0)
	// char arry = arrx[0] <==> *(arrx + 0)
	// char arx =  (arr[0])[0] <==> *(*(arr + 0) + 0));
	// arr[3][1] <==> *(*(arr + 3) + 1)

	show_array(5, arr);


	return 0;

}

