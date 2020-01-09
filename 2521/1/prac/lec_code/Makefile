CC=clang
CFLAGS=-Wall -Werror -std=c99 -g
LDFLAGS=-g -lm
BINS=stack_linked_list

all: $(BINS)

stack_linked_list:	stack_linked_list.o stack.o linked_list.o 
	${CC} -o stack_linked_list stack_linked_list.o stack.o linked_list.o 

stack_linked_list.o:	stack_linked_list.c stack.h linked_list.h
stack.o:	stack.h item.h
linked_list.o:	linked_list.h linked_list.c item.h

clean:
	-rm -f stack_linked_list *.o core

