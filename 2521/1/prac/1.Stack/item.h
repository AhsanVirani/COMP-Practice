
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#ifndef CS2521__ITEM_H_
#define CS2521__ITEM_H_

#define __unused __attribute__((unused))

typedef int Item;


static inline Item item_clone (Item it) { return it; }
static inline void item_drop (Item it __attribute__((unused))) { return; }
static inline bool item_eq (Item a, Item b) { return a == b; }
static inline int item_ord (Item it __unused) { return 1; }
static inline char *item_show (Item it) {
	char *x = NULL; sprintf (x, "%d", it); return x; }
static inline size_t item_size (Item it __unused) { return sizeof(Item); }

#define Item Item

#endif // !defined(CS2521__ITEM_H_)

