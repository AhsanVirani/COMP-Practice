#include <stdio.h>

int
main(void)
{
	
	char myChar = '\0';

	while(myChar != EOF)
	{
		myChar = getchar();
	
		printf("%d on %c\n", myChar, myChar);

	}

	printf("stopped intentionally\n");

	return 0;
}
