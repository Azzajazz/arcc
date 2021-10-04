#include "list.h"
#include "utils.h"

#include <stdio.h>

list_t* list_create_with_size(size_t init_size)
{
    list_t* list = malloc(sizeof(*list));
    list->elems = malloc(init_size * sizeof(*(list->elems)));
    list->nelems = 0;
    list->capacity = init_size;
}

list_t* list_create()
{
    return list_create_with_size(0);
}

void list_push_front(list_t* list, void* elem)
{
    if (list->capacity <= list->nelems)
    {
        list->elems = try_realloc(list->elems, (list->nelems + 1) * sizeof(*(list->elems)));
        list->capacity = list->nelems + 1;
    }

    for (int i = list->nelems; i > 0; i++)
        list->elems[i] = list->elems[i - 1];
    
    list->elems[0] = elem;
    list->nelems += 1;
}

void list_push_back(list_t* list, void* elem)
{
    if (list->capacity <= list->nelems)
    {
        list->elems = try_realloc(list->elems, (list->nelems + 1) * sizeof(*(list->elems)));
        list->capacity = list->nelems + 1;
    }
    list->elems[list->nelems] = elem;
    list->nelems += 1;
}

void* list_at_index(list_t* list, int index)
{
    return list->elems[index];
}

size_t list_size(list_t* list)
{
    return list->nelems;
}