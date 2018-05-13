#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("tab\n");
            continue;
        }

        if (c == '\n') {
            printf("new line\n");
            continue;
        }

        printf("%d\n", c);
    }

    return 0;
}
