CC=gcc
CCFLAGS=-Wall -Werror
LDFLAGS=-g -lm
BINS=stack_test_black derpcalc brackets

.PHONY: all clean

all: $(BINS)

clean:
	-rm -f $(BINS) *.o core

brackets:	brackets.o stack_linked_list.o linked_list.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

derpcalc:	derpcalc.o stack_linked_list.o linked_list.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

stack_test_black:	stack_test_black.o stack_linked_list.o linked_list.o
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)


linked_list.o:	%.o : %.c item.h
stack_linked_list.o:	stack.h stack_linked_list.c linked_list.h
stack_test_black.o:	stack_test_black.c stack_linked_list.o linked_list.o
derpcalc.o:	derpcalc.c stack_linked_list.o linked_list.o
brackets.o:	brackets.c stack_linked_list.o linked_list.o

