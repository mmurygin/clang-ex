#include <stdio.h>

#define ARRAY_SIZE 100

int binsearch(int x, int v[], int n);

int main()
{
    // Generate source array
    int arr[ARRAY_SIZE] = { 0 };
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        arr[i] = i * 10;
    }

    printf("Input integer to search:\n");

    int to_search;
    scanf("%d", &to_search);

    int res = binsearch(to_search, arr, ARRAY_SIZE);

    printf("Result: %d\n", res);

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int min_i = 0;
    int max_i = n - 1;

    while (min_i <= max_i)
    {
        int i = (max_i + min_i) / 2;

        if (v[i] > x)
        {
            max_i = i - 1;
        }
        else if (v[i] < x)
        {
            min_i = i + 1;
        }
        else
        {
            return i;
        }
    }

    return -1;
}
