#include <stdio.h>
#include <stdbool.h>

int main() {
    int c = 0;
    bool new_word = false;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if (new_word) {
                continue;
            } else {
                new_word = true;
                putchar('\n');
            }
        } else {
            new_word = false;
            putchar(c);
        }
    }

    return 0;
}
