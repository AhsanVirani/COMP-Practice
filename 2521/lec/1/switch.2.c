#include <stdio.h>



int
main(void)
{
	char color[5] = {'w', 'g', '\0', 'y', 'r'};
	// char *color -> address;
	char *character_0 = color;
	//printf("%x\n", color);
	//printf("%x\n", character_0);
	printf("%d\n", sizeof(int));
	putchar(*color);
	printf("%c\n", *color);

	
	printf("%s\n", color); // string %s formatter takes pointer to char and reads until '\0' seen

	printf("%s\n", color+sizeof(char)*4);
	putchar(119);


	return 0;
}


