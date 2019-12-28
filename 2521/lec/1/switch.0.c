#include <stdio.h>


void
flagFunction(void)
{
	char color[5] = {'w', 'g', 'b', 'y', 'r'};
	
	for(int i = 0; i < 5; i++)
	{
		switch(color[i])
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

	flagFunction();

	return 0;

}


