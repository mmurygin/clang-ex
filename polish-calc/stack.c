#include <stdio.h>
#include <stdlib.h>

int sp = 0;
double * stack = NULL;

void init_stack(int size)
{
    stack = malloc(sizeof(double) * size);
}

void cleanup_stack()
{
    free(stack);
    stack = NULL;
}

void push(double value)
{
    stack[sp++] = value;
}

double pop()
{
    if (sp > 0)
    {
        return stack[--sp];
    }
    else
    {
        puts("Error stack is empty");
        return 0.0;
    }
}
