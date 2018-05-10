#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("tab");
        }

        if (c == '\n') {
            printf("new line");
        }
    }

    return 0;
}
