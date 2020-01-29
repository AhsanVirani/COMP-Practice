#include <stdio.h>

int
main(void)
{
	
	char myChar = '\0';
	int nchars = 0;
	while(myChar != EOF)
	{
		myChar = getchar();
		nchars++;
		printf("%d on %c\n", myChar, myChar);

	}
	
	printf("stopped intentionally\n");
	printf("count = %d\n", nchars);

	return 0;
}
