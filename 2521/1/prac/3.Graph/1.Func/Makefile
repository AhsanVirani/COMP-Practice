CC=gcc
CCFLAGS=-Wall -Werror -std=c99
LDFLAGS=-g -lm

BINS=node_test list_test

.PHONY: all clean

all: $(BINS)

clean:
	-rm -f $(BINS) *.o core

node_test:	node_test.o node.o item.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

list_test:	list_test.o list.o node.o item.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

item.o:	item.h item.c
node.o:	node.h node.c item.h
list.o:	list.h list.c node.h item.h
