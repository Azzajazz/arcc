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

void handle_error(const char* msg, const char* fn)
{
    fprintf(stderr, "::%s:: %s\n", fn, msg);
    exit(-1);
}

char* read_src_file(const char* path)
{
    size_t src_size = 1024;
    char* src = malloc(1024);
    FILE* fp = fopen(path, "r");
    if (!fp)
        handle_error("Could not open file", __func__);
    
    size_t n = fread(src, 1, 1024, fp);
    while (n == 1024)
    {
        src_size += 1024;
        src = try_realloc(src, src_size);
        n = fread(src + src_size - 1024, 1, 1024, fp);
    }
    fclose(fp);

    return src;
}