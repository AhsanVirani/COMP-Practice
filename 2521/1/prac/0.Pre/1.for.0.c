#include <stdio.h>

int
main(void)
{
	int sum = 0; 
	for(int i = 0; i < 10; i+=2) // i = i + 2;
	{
		sum += i; // sum = sum + i; sum+=2 -> sum = sum + 2;
		printf("%d\n", sum);		
	}

	return 0;

}
