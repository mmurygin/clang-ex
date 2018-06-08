#include <stdio.h>
#include <stdlib.h>

static char ** initial_head = NULL;
static char ** initial_tail = NULL;
static char ** head = NULL;
static char ** tail = NULL;
static int length = 0;

void init_queue(int capacity)
{
    initial_head = malloc(sizeof(char*) * capacity);
    initial_tail = initial_head + capacity;
    head = initial_head;
    tail = initial_head;
}

void free_queue()
{
    free(initial_head);
}

void enqueue(char * str)
{
    if (tail == head)
    {
        if (length > 0)
        {
            printf("Error: queue overflow exception");
            return;
        }

        if (tail == initial_tail)
        {
            tail = initial_head;
        }
    }

    if (tail > head)
    {
        if (tail == initial_tail && head == initial_head)
        {
            printf("Error: queue overflow exception");
            return;
        }

        if (tail == initial_tail)
        {
            tail = initial_head;
        }
    }

    *tail = str;
    ++tail;
    ++length;
}

char * dequeue()
{
    if (length == 0)
    {
        printf("Error: there are to elements to dequeue");
        return NULL;
    }

    if (head == initial_tail)
    {
        head = initial_head;
    }

    char * str = *head;

    ++head;
    --length;

    return str;
}

int queue_len()
{
    return length;
}
