#include <stdio.h>

void swap(int * arr, int from, int to)
{
    int val = arr[from];
    arr[from] = arr[to];
    arr[to] = val;
}

void print_array(const int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    putchar('\n');
}
