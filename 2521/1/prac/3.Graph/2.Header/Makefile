CC		:= gcc
CCFLAGS	:= -Wall -Werror -std=c99
LDFLAGS	:= -g -lm

TARGETS	:= node_test list_test
MAINS	:= $(addsuffix .o, $(TARGETS) )
OBJ		:= item.o node.o list.o $(MAINS)
DEPS	:= item.h node.h list.h

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS) $(OBJ)


$(OBJ): %.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS)

$(TARGETS): % : $(filter-out $(MAINS), $(OBJ)) %.o
	$(CC) -o $@ $(LIBS) $^ $(CCFLAGS) $(LDFLAGS)

