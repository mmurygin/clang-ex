#include <stdio.h>
#include <stdlib.h>
#include "include/array.h"

#define MAX_ARRAY_SIZE 100

void insertion_sort(int * arr, int len);

int equality_checks = 0;

int main() {
    int * arr = malloc(sizeof(int) * MAX_ARRAY_SIZE);

    puts("Please enter integer sequence to sort (finish with ctrl+d)");

    int val;
    int arr_len = 0;
    while ((scanf( "%d", &val)) == 1) {
        arr[arr_len++] = val;
    }

    insertion_sort(arr, arr_len);

    print_array(arr, arr_len);
    printf("Equality checks: %d\n", equality_checks);
    free(arr);

    return 0;
}

void insertion_sort(int * arr, int len)
{
    for (int sorted_edge = 1; sorted_edge < len; ++sorted_edge)
    {
        for (int i = sorted_edge; i > 0; --i)
        {
            ++equality_checks;
            if (arr[i] < arr[i-1])
            {
                swap(arr, i, i-1);
            }
            else
            {
                break;
            }

        }
    }
}
