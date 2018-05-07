#include <stdio.h>

#define LENGTH 10

int main() {
    int arr [LENGTH] = {0};

    for (int i = 0; i < LENGTH; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
