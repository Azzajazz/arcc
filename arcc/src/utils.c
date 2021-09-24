#include "utils.h"

#include <stdio.h>

void* try_realloc(void* ptr, size_t size)
{
    void* tmp = realloc(ptr, size);
    if (tmp == NULL)
    {
        perror("Realloc failed!");
        exit(1);
    }
    return tmp;
}