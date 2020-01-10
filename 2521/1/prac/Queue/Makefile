CC=gcc
CFLAGS=-Wall -Werror -std=c99
LDFLAGS=-g -lm
BINS=item_test

all:	$(BINS)

item_test: item_test.o item.o
	$(CC) $(CFLAGS) -o item_test item_test.o item.o


item.o:	item.h item.c
item_test.o:	item_test.c item.h item.c

clean:
	-rm -f $(BINS) *.o core
