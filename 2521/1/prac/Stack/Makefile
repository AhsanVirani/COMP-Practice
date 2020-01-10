CC=gcc
CFLAGS=-Wall -Werror -std=c99
LDFLAGS=-g -lm
BINS=stack_test_black

all: $(BINS)

stack_test_black:	stack_test_black.o stack_linked_list.o linked_list.o
	$(CC) $(CFLAGS) -o stack_test_black stack_test_black.o stack_linked_list.o linked_list.o $(LDFLAGS)


linked_list.o:	linked_list.h linked_list.c item.h
stack_linked_list.o:	stack.h stack_linked_list.c linked_list.h
stack_test_black.o:	stack_test_black.c stack_linked_list.o linked_list.o

clean:
	-rm -f stack_test_black *.o core

