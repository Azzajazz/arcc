#ifndef ARCC_UTILS_H
#define ARCC_UTILS_H

#include <stdlib.h>
#include <stdio.h>

#define MIN(a, b)           \
({                          \
    __typeof__ (a) _a = (a);\
    __typeof__ (b) _b = (b);\
    _a < _b ? _a : _b;      \
})

#define MAX(a, b)           \
({                          \
    __typeof__ (a) _a = (a);\
    __typeof__ (b) _b = (b);\
    _a > _b ? _a : _b       \
})

void* try_realloc(void* ptr, size_t size);

void handle_error(const char* msg, const char* fn);

char* read_src_file(const char* filename);

#endif