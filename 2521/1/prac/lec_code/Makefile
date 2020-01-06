CC=clang
CFLAGS=-Wall -Werror -std=c99 -g
LDFLAGS=-g -lm
BINS=derpcalc

all: $(BINS)

derpcalc:	derpcalc.o stack.o
	${CC} derpcalc derpcalc.o stack.o

derpcalc.o:	derpcalc.c stack.h
stack.o:	stack_array.c stack.h

clean:
	-rm -f derpcalc derpcalc.o stack.o core

