#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "list.h"

typedef struct vertex {
	char	*name;

	list	edges;
} vertex;

//typedef struct _graph *graph;

int
main (void)
{
//	vertex *graph = {NULL, NULL, NULL, NULL};
	vertex graph[4];
	vertex v1 = (vertex){.name = "Khi", .edges = NULL}



	return 0;

}


int
array_graph(void)
{
	//char *ct = "Khi";
	char *cities[] = {"Khi", "Lhr", "Islb", "Phsw", NULL};
	int i = 0;
	for (char *c = cities[0]; c != NULL; c = cities[i])
	{
		printf("vertex: %s\n", c);
		i++;
	}
	int road[4][4];
	for (int e_1 = 0; e_1 < 4; e_1++)
	{
		for (int e_2 = 0; e_2 < 4; e_2++)
		{
			road[e_1][e_2] = 0;
		}
	}

	road[0][1] = 1;
	road[1][0] = 1;
	road[2][3] = 1;

	for (int e_1 = 0; e_1 < 4; e_1++)
	{
		for (int e_2 = 0; e_2 < 4; e_2++)
		{
			if (road[e_1][e_2] == 1)
			{
				printf("vertex: %s <-edge-> vertex: %s\n", cities[e_1], cities[e_2]);
			}
		}
	}

	return 0;
}


