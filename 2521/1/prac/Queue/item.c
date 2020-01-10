#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "item.h"


Item 
item_clone (Item it){
	assert(it != NULL);
	Item c_it = NULL;

   /** getting size of array */ 
	int it_len = 0;
	while(it[it_len] != '\0')
	{
		it_len++;
	}
	c_it = calloc((it_len+1), sizeof((*c_it)));
	if(c_it == NULL)
	{
		fprintf(stderr, "Memory out of bound");
		exit(EXIT_FAILURE);
	}	
	
	for(int i = 0; it[i] != '\0'; i++)
	{
		c_it[i] = it[i];
	}
	c_it[it_len] = '\0';
	
	return c_it;
}

void
item_free (Item it)
{
	assert(it != NULL);
	free(it);
}




