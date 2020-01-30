#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
atom://teletype/portal/af4eb322-1c98-456b-94b4-6a24225fdc43
typedef struct _node *node;

typedef struct _node {
	char	*name;
	void	*data;
	node	next;
	node	prev;
} _node;

int
main(void)
{
	node cities = (node)malloc(sizeof(*cities));
	cities->name = "Karachi";
	cities->next = (node)malloc(sizeof(*cities));
	cities->next->name = "Islamabad";
	cities->next->next = (node)malloc(sizeof(*cities));
	cities->next->next->name = "Rawalpindi";
	cities->next->next->next = NULL;

	node karachi = (node)malloc(sizeof(*karachi));
	karachi->name = "Gulshan";
	karachi->next = (node)malloc(sizeof(*karachi));
	karachi->next->name = "Jouhar";
	karachi->next->next = (node)malloc(sizeof(*karachi));
	karachi->next->next->name = "Liyari";
	karachi->next->next->next = NULL;

	node islamabad = (node)malloc(sizeof(*islamabad));
	islamabad->name = "Defence";
	islamabad->next = (node)malloc(sizeof(*islamabad));
	islamabad->next->name = "F-Sector";
	islamabad->next->next = (node)malloc(sizeof(*islamabad));
	islamabad->next->next->name = "G-Sector";
	islamabad->next->next->next = NULL;

	node rawalpindi = (node)malloc(sizeof(*rawalpindi));
	rawalpindi->name = "R1";
	rawalpindi->next = (node)malloc(sizeof(*rawalpindi));
	rawalpindi->next->name = "R2";
	rawalpindi->next->next = NULL;

	cities->data = karachi;
	cities->next->data = islamabad;
	cities->next->next->data = rawalpindi;

	for(node curr = cities; curr != NULL; curr = curr->next)
	{
		printf("Welcome to %s city\n", curr->name);
		for(node ncurr = curr->data; ncurr != NULL; ncurr = ncurr->next)
			printf("Your suburb is %s\n", ncurr->name);
	}

	return EXIT_SUCCESS;
}
