#include <stdio.h>
#include <stdlib.h>

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

int init_array (int ** arr_pointer, int max_size)
{
    *arr_pointer = malloc(sizeof(int) * max_size);

    puts("Please enter integer sequence to sort (finish with ctrl+d)");

    int val;
    int i = 0;
    while (i < max_size && scanf("%d", &val) == 1)
    {
        *arr_pointer[i++] = val;
    }

    return i == max_size ? i - 1 : i;
}
