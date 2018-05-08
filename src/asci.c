// prints asci code of a charactoer

#include <stdio.h>

int main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
        } else {
            printf("%d ", (int)c);
        }
    }

    return 0;
}
