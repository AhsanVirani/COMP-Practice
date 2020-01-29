#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "queue.h"
#include "linked_list.h"

typedef struct queue{
	node h;	node t;	
} queue;

Queue
queue_new(void)
{	
	Queue new = malloc(sizeof(*new));
	assert(new != NULL);
	new->h = NULL;	new->t = NULL;

	return new;

}

void 
queue_destroy(Queue q)
{
	assert(q != NULL);
	if (q->h != NULL) linkedListDestroy(q->h);
	free(q);

}

// Remember to free d
Item 
queue_pop(Queue q)
{

	assert(q != NULL);
	Item d = get_data(q->h);
	node temp = q->h;
	q->h = get_next(q->h);
	
	if(q->h == NULL)	q->t = NULL;	
	
	free(temp);

	return d;
}

void 
queue_push(Queue q, Item d)
{
	assert(q != NULL && d != NULL);
	node n = new_node();
	set_data(n, item_clone(d));

	if(q->h == NULL) { q->h = n; q->t = n; } // two lines thats why brackets needed one line is fine w/o bracket

	set_next(q->t, n);
	set_prev(n, q->t);
	q->t = n;
	
}


size_t 
queue_size(Queue q)
{
	size_t count = 0;
	//if (s->n == NULL) return 0;
	for(node c = q->h; c != NULL; c = get_next(c))
	{
		count++;

	}
	return count;


}







