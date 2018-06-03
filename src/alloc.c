#include <stdio.h>

#define ALLOC_SIZE 100000

static char alloc_buffer[ALLOC_SIZE];
static char *alloc_pointer = alloc_buffer;

char *alloc(int size)
{
    printf("Free: %u\n", alloc_buffer + ALLOC_SIZE - alloc_pointer);

    if (size > alloc_buffer + ALLOC_SIZE - alloc_pointer)
    {
        puts("Out Of memory");
        return NULL;
    }

    char * p = alloc_pointer;

    alloc_pointer+=size;

    return p;
}

void afree(char * p)
{
    alloc_pointer = p;
}
