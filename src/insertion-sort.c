#include "include/array.h"

#define MAX_ARRAY_SIZE 100

void insertion_sort(int * arr, int len);

int equality_checks = 0;

int main() {
    int * arr = 0;
    int arr_len = init_array(&arr, MAX_ARRAY_SIZE);

    insertion_sort(arr, arr_len);

    print_array(arr, arr_len);

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
