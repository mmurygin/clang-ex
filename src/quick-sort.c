#include <stdlib.h>
#include "include/array.h"

#define MAX_ARRAY_SIZE 100

void quick_sort(int *from, int *to);

int main()
{
    int *arr = NULL;

    int len = init_array(&arr, MAX_ARRAY_SIZE);

    quick_sort(arr, arr + len);

    print_array(arr, len);

    free(arr);

    return 0;
}

void quick_sort(int *from, int *to)
{
    if (from >= to)
    {
        return;
    }

    int len = to - from;
    int pivot = len - 1;

    for(int i = len - 1; i > 0; --i)
    {
        if (from[i - 1] > from[pivot])
        {
            swap(from, i - 1, pivot);
            pivot = i - 1;
        }
    }

    quick_sort(from, from + pivot);
    quick_sort(from + pivot + 1, to);
}
