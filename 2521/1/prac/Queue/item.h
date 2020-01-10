#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifndef PRAC__ITEM_H 
#define PRAC__ITEM_H

#define __unused __attribute__((unused))

typedef char *Item;

Item 
item_clone (Item);

void
item_free (Item);


#endif
