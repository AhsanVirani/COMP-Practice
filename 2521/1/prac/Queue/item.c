#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "item.h"

size_t
item_size (Item it)
{
	return sizeof(*it);
}

size_t
item_len (Item it)
{
	assert(it != NULL);
	/** getting size of array */ 
	size_t it_len = 0;
	while(it[it_len] != '\0')
	{
		it_len++;
	}

	return (it_len + 1);
}

bool 
item_eq (Item i1, Item i2)
{
	assert(i1 != NULL && i2 != NULL);

	int i = 0;
	while( (i1[i] != '\0' || i2[i] != '\0') && i1[i] == i2[i])
	{
		i++;
	}
	if(i1[i] == '\0' && i2[i] == '\0')	return true;
	else	return false;

}

void
item_show (Item it)
{
	assert(it != NULL);
	printf("%s\n", it);
}


Item 
item_clone (Item it){
	assert(it != NULL);
	Item c_it = NULL;

   size_t it_len = item_len(it);
	c_it = calloc((it_len), sizeof(item_size(it)));
	if(c_it == NULL)
	{
		fprintf(stderr, "Memory out of bound");
		exit(EXIT_FAILURE);
	}	
	
	for(int i = 0; it[i] != '\0'; i++)
	{
		c_it[i] = it[i];
	}
	c_it[it_len-1] = '\0';
	
	return c_it;
}

void
item_drop (Item it)
{
	assert(it != NULL);
	free(it);
}







