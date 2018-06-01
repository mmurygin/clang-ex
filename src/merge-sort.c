#include <stdlib.h>
#include "include/array.h"

#define MAX_ARRAY_SIZE 100

void merge_sort(int *from, int *to);
void combine(int *from, int *middle, int *to);

int main()
{
    int * arr = NULL;

    int len = init_array(&arr, MAX_ARRAY_SIZE);

    merge_sort(arr, arr + len);

    print_array(arr, len);

    free(arr);

    return 0;
}

void merge_sort(int * from, int * to)
{
    if (to - from == 1)
    {
        return;
    }

    int half_len = (to - from) / 2;
    merge_sort(from, from + half_len);
    merge_sort(from + half_len, to);
    combine(from, from + half_len, to);
}

void combine(int *from, int *middle, int *to)
{
    static int * inter_arr = NULL;

    if (!inter_arr)
    {
        inter_arr = malloc(sizeof(int) * MAX_ARRAY_SIZE);
    }

    int i1 = 0;
    int i2 = 0;
    int len = to - from;

    while (i1 + i2 < len)
    {
        if (i1 >= middle - from)
        {
            inter_arr[i1 + i2] = middle[i2++];
        }
        else if (i2 >= to - middle)
        {
            inter_arr[i1 + i2] = from[i1++];
        }
        else if (from[i1] <= middle[i2])
        {
            inter_arr[i1 + i2] = from[i1++];
        }
        else
        {
            inter_arr[i1+i2] = middle[i2++];
        }
    }

    copy_array(inter_arr, from, len);
}
