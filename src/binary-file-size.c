#include <stdio.h>

#define ARRAY_SIZE 100000000

static int arr[ARRAY_SIZE] = { 0 };

int main() {
    long i = ARRAY_SIZE;
    while (1) {
        if (i < 0)
        {
            i = ARRAY_SIZE;
        }

        putchar(arr[--i] + 48);
    }

    return 0;
}
