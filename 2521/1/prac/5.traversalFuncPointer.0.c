#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_LEN 10


int
main(void)
{
	int *arr = (int *)malloc(sizeof(int)*ARR_LEN);
	// malloc doesn't live inside any arbitary function but can survive throughout the lifetime of program
	// Must kill malloc at the end of whole program.

	printf("%d\n", *arr);
	for(int i = 0; i < ARR_LEN; i++)
	{
		// doesnt have to specify sizeof(datatype) when performing pointer arithmetic
		// Auto moves block size from start <! IMPORTANT />
		printf("before %d\n", *(arr + i)); //*(arr + i) == arr[i]
		printf("before %d\n", *(arr + i));
		*(arr + i) = i;
		printf("after %d\n", *(arr + i));
	}
	for(int i = 0; i < ARR_LEN; i++)
	{
		printf("i-> %d\n", i);
		printf("arr[i]-> %d\n", *(arr + i));
	}
	free(arr);	
	//printf("arr at %p has %d * %d for int at %p\n", &arr, sizeof(int), ARR_LEN, arr);
	//populateArray(arr, 20);
	return 0;
}
