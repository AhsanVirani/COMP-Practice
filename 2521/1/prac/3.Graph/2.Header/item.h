#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#ifndef PRAC__ITEM_H 
#define PRAC__ITEM_H

#define __unused __attribute__((unused))

typedef char *Item;

Item 
item_clone (Item);

void
item_drop (Item);

void
item_show (Item);

bool 
item_eq (Item, Item);

size_t
item_size (Item it);

size_t
item_len (Item it);

#endif

