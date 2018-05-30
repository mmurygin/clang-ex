#include <stdlib.h>

int sp = 0;
int * stack = NULL;

void init_stack(int size)
{
    stack = malloc(sizeof(int) * size);
}

void cleanup_stack()
{
    free(stack);
    stack = NULL;
}

void push(int value)
{
    stack[sp++] = value;
}

int pop()
{
    return stack[--sp];
}
