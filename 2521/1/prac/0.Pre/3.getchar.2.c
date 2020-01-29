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
	char *internalStringVariable = "Thank you \0 so much!";
	char internalStringVariable0[3] = "Thanks";
		
		// No difference between the two. char * dynamic while char is static. Everything waits for \0 to cease. 	
	puts(internalStringVariable0);
	puts("Thank you so much!");		

	return 0;

}
