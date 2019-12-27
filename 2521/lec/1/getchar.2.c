#include <stdio.h>
#include <ctype.h>

int
main(void)
{
	
	char myChar = '\0';
	
	while((myChar = getchar()) != EOF)
	{
	
		if(myChar == '\n')	continue;
		if(myChar == 'q')	return 0;
		if((isalpha(myChar)) == 0) continue;
		putchar(myChar);
		putchar(10);

	}

	return 0;

}
