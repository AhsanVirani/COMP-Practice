#include <stdio.h>


void
flagFunction(char colour)
{
	//char color[5] = {'w', 'g', 'b', 'y', 'r'};
	
	//for(int i = 0; i < 5; i++)
	//{
		switch(colour)
		{
			case 'g': puts("Your color is green"); /*printf("at %d\n", i);*/ break;
		
			case 'w': puts("Your color is white");/* printf("at %d\n", i);*/ break;

			default: puts("Something else"); /*printf("at %d\n", i);*/ 
		}
	
	//}

}

int
main(void)
{
	char color[5] = {'w', 'g', 'b', 'y', 'r'};
	printf("%x\n", color);
	
	flagFunction(color[0]);
	flagFunction('g');

	return 0;

}
