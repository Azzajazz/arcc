#ifndef ARCC_LIST_H
#define ARCC_LIST_H

#include <stdlib.h>

typedef struct LIST_STRUCT
{
    void** elems;
    int nelems;
    int capacity;
} list_t;

list_t* list_create_with_size(size_t init_size);

list_t* list_create();

void list_push_front(list_t* list, void* elem);

void list_push_back(list_t* list, void* elem);

void* list_at_index(list_t* list, int index);

void* list_pop(list_t* list);

size_t list_size(list_t* list);

#endif