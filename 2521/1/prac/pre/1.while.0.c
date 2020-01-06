#include <stdio.h>

int
main(void)
{

	int sum = 0, i = 0;
	while(i < 10)
	{
		
		sum = sum + i;
		printf("%d\n", sum);
		i++;
	}

	return 0;
}
