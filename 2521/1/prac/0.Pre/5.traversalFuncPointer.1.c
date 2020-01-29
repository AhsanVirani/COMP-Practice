#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

void
traversal_1_1(int *traverse, void (*operation)(int *))
{	// void (*operation)(int *) = showValue
	for(int i = 0; i < ARR_LEN; i++)
	{
		//showValue(traverse + i) <!> traverse + i == &(traverse[i])
		operation(traverse + i);
	}
}

void
traversal_1_2(int *traverse, void (*operation)(int *, int))
{	
	for(int i = 0; i < ARR_LEN; i++) { operation(traverse + i, i); }

}

void
traversal_2_2(int *traverse, void (*operation)(int *, int), int n)
{
	for(int i = 0; i < ARR_LEN; i++) { operation(traverse + i, n); }
	
}

void
traversal_3_3(int *traverse, void (*operation)(int *, int), int (*tool)(void))
{
	for(int i = 0; i < ARR_LEN; i++) { operation(traverse + i, tool()); }
	
}

void
showPointerValue(int *box) { printf("%p has %d\n", box, (*box)); }

void
showValue(int *box) { printf("%d\n", (*box)); }

void
setValue(int *box, int value) { *box = value; }

void
showMod2(int *box) { if (*box % 2 == 0) printf("%p has %d\n", box, (*box)); }

void
showMod2Adv(int *box) { if (*box % 2 == 0) showPointerValue(box); }

void
showModNAdv(int *box, int n) { if (*box % n == 0) showPointerValue(box); }


int
main(void)
{
	// int *arr = malloc(sizeof(int)*ARR_LEN);
	int *arr = (int *)calloc(ARR_LEN, sizeof(int)); //advance version of malloc which creates space and initialises
	if(arr == NULL) 
	{ 
		fprintf(stderr, "Failed to allocate memory");
		exit(EXIT_FAILURE);		
	
	}

	traversal_1_1(arr, &showValue);
	traversal_1_1(arr, &showPointerValue);
/*	same as _|^
	for(int i = 0; i < ARR_LEN; i++)
	{
		printf("i-> %d\n", i);
		printf("arr[i]-> %d\n", *(arr + i));
	}
*/
	traversal_1_2(arr, &setValue);
	traversal_1_1(arr, &showPointerValue);

	traversal_1_1(arr, &showMod2);

	traversal_1_1(arr, &showMod2Adv);
	traversal_2_2(arr, &showModNAdv, 4);


	traversal_3_3(arr, &setValue, &rand);
	traversal_1_1(arr, &showValue);
	traversal_2_2(arr, &showModNAdv, 2);

	
	
/*
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
*/
	free(arr); arr = NULL;	
	//printf("arr at %p has %d * %d for int at %p\n", &arr, sizeof(int), ARR_LEN, arr);
	//populateArray(arr, 20);
	return 0;
}
/*
0d
{0,1,2,3,4,5,6,7,8,9}
0000
0001
0002
..
..
..
0009
0010
---
0x
{0,1,2,3,4,5,6,7,8,9, a, b, c, d, e, f}
0000
0001
0002
..
..
..
0009
000a
000b
000c
000d
000e
000f
0010

*/







