#include <stdio.h>


void flagFunction(char *colour)
{
	printf("im in function: flagFunction() colour address -> %x\n", colour);
	colour[2] = 'G';
	//char color[5] = {'w', 'g', 'b', 'y', 'r'};
	
	for(int i = 0; colour[i] != '\0'; i++)
	{
		switch(colour[i])
		{
			case 'g': puts("Your color is green"); printf("at %d\n", i); break;
		
			case 'w': puts("Your color is white"); printf("at %d\n", i); break;

			default: puts("Something else"); printf("at %d\n", i); 
		}
	
	}

}

int
main(void)
{
	char color[5] = {'w', 'g', 'b', 'y', 'r'};
	// char *color -> address;
	printf("%x\n", color);
	//printf("%x\n", character_0);

	printf("%s\n", &color);

	flagFunction(color);

	printf("%c\n", color[2]);
	//flagFunction('g');

	return 0;

}


