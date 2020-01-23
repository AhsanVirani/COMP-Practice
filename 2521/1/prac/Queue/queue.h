#include <stdio.h>

#include "item.h"

#ifndef PRAC__QUEUE_H_
#define PRAC__QUEUE_H_

typedef struct queue *Queue;

// Create a new empty queue
Queue queue_new(void);

// Destroying Queue, releasing all resources associated with it
void queue_destroy(Queue);

// Remove an item from top of the Queue
Item queue_pop(Queue);

// Insert an item at the bottom of Queue
void queue_push(Queue, Item);

// Get the number of items in a Queue
size_t queue_size(Queue);


#endif

