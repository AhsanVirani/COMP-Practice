CC=gcc
CFLAGS=-Wall -Werror -std=c99
LDFLAGS=-g -lm
BINS=item_test queue_test

all:	$(BINS)

queue_test: queue_test.o queue_linkedlist.o doubly_linkedlist.o item.o
	$(CC) $(CFLAGS) -o queue_test queue_test.o queue_linkedlist.o doubly_linkedlist.o item.o

item_test: item_test.o item.o
	$(CC) $(CFLAGS) -o item_test item_test.o item.o $(LDFLAGS)

item.o:	item.h item.c
doubly_linkedlist.o:	linked_list.h doubly_linkedlist.c item.h
queue_linkedlist.o:	queue.h queue_linkedlist.c linked_list.h item.h
queue_test.o:	queue_test.c queue.h item.h

item_test.o:	item_test.c item.h

clean:
	-rm -f $(BINS) *.o core
