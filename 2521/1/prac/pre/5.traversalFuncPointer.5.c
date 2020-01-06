#include <stdio.h>
#include <stdlib.h>

void
traverse(size_t b, char ** array1, int(*f)(const char *) )
{

	for(size_t i = 0; i < b; i++)
	{
		(*f) (array1[i]);
		
	}

}


void
show_array(size_t a, char **array) 
{
	puts ("[");
	traverse(a, array, &puts);
	puts("]");
}


typedef char *Item;

typedef struct _node *node;
typedef struct _node {
	Item	data;
	node	next;
} _node;


Item
create_item(Item str, size_t size) 
{
	Item item = calloc(size, sizeof((*item)));
	for(int i = 0; i < size; i++)
	{
		*(item + i) = *(str + i);
		//item[i] = str[i];
	}
	
	return item;
}

void
set_node_next(node source, node next)
{
	(*source).next = next;
}

void
set_node_data(node source, Item data)
{
	(*source).data = data;
}


node
create_node_set_data(node set_next, Item set_data)
{
	node new_node = malloc(sizeof(*new_node)); // struct _node *n = malloc(sizeof(struct _node)) <==> _node *n = malloc(sizeof(_node))

	set_node_next(new_node, set_next);	//*(new_node).next = set_next;
	set_node_data(new_node, set_data);	//*(new_node).data = set_data; 
	
	return new_node;
}

node
create_node_create_item(node set_next, Item str, size_t size)
{
	Item data = create_item(str, size);
	node new_node = create_node_set_data(set_next, data);

	return new_node;
}

Item *
traverse_arr_create_arr(size_t s, Item *arr1, Item(*f)(Item) )
{
	Item *arr2 = calloc(s, sizeof(Item));
	for(size_t i = 0; i < s; i++)
	{
		arr2[i] = (*f) (arr1[i]);

	} 
	return arr2;
}

node
traverse_arr_create_list(size_t s, Item *arr1, Item (*f)(Item, size_t) )
{
	node head = NULL, curr = NULL;
	for(size_t i = 0; i < s; i++)
	{
		if (head == NULL) 
		{
 			curr = create_node_set_data(NULL, (*f) (arr1[i], s));
			head = curr;
		} else {
			set_node_next(curr, create_node_set_data(NULL, (*f) (arr1[i], s)));
			curr = (*curr).next; 	// curr = curr->next;
		}
	} 
	return head;
}

void
traverse_list(node head, int (*f) (const char *))
{
	for(node curr = head; curr != NULL; curr = (*curr).next)
	{
		(*f) ((*curr).data);
	}
}

void
traverse_list_free(node head)
{
	for(node curr = head; curr != NULL; curr = (*curr).next)
	{
		free((*curr).data); (*curr).data = NULL;
	}
}

void
list_free_recursive(node n)
{
	if(n->next == NULL)
	{
		free(n); 
		return;
	} else {
		list_free_recursive((*n).next);
		free(n);
		return;
	}
}

void
list_show_reverse_recursive(node n)
{
	if(n->next == NULL)
	{
		//free(n);
		printf("%s\n", n->data); 
		return;
	} else {
		list_show_reverse_recursive((*n).next);
		//free(n);
		printf("%s\n", n->data);
		return;
	}
}


int
main(void)
{
	//char * *arr 
	Item *arr = malloc(sizeof(*arr) * 5); // so arr is a pointer of pointers to characters meaning *(arr)[5] = {'','','','',''}
	
	
// char ** arr <==> char * arr[]

	for(int i = 0; i < 5; i++)
	{
		Item arr1 = calloc(5, sizeof(*arr1)); //arr[5] = {'A','A','A','A','\0'}
		for(int j = 0; j < 4; j++)
		{
			arr1[j] = 65 + i;
			//putchar(*(arr1));
			
		}
		
		*(arr + i) = arr1; // arr[i] = arr1;
		
		
	}
	// char *arrx = arr[0] <==> *(arr + 0)
	// char arry = arrx[0] <==> *(arrx + 0)
	// char arx =  (arr[0])[0] <==> *(*(arr + 0) + 0));
	// arr[3][1] <==> *(*(arr + 3) + 1)

	show_array(5, arr);

	printf("showing linked list\n");
	node h = traverse_arr_create_list(5, arr, &create_item);
	traverse_list(h, &puts);

	list_show_reverse_recursive(h);

	for(int i = 0; i < 5; i++)
	{
		free(arr[i]);	
		arr[i] = NULL;
	}
	
	free(arr); arr = NULL;
	
	traverse_list_free(h);
	list_free_recursive(h);


	return 0;

}

