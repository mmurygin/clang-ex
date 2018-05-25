#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

void insertion_sort(int * arr, int len)
{
    return;
}

int main() {
    int * arr = malloc(sizeof(int) * MAX_ARRAY_SIZE);

    puts("Please enter integer sequence to sort (split with spaces, finish with new line)");

    int val;
    int arr_len = 0;
    while ((scanf( "%d", &val)) == 1) {
        arr[arr_len++] = val;
    }

    insertion_sort(arr, arr_len);

    for (int i = 0; i < arr_len; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}
