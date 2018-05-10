// Exercise 1-9.
// Write a program to copy its input to its output, replacing each string of one or more blanks
// by a single blank.

#include <stdio.h>
#include <stdbool.h>

int main() {
    int c = 0;
    bool last_blank = false;

    while((c = getchar()) != EOF) {
        if (c == ' ') {
            if (last_blank) continue;
            else last_blank = true;
        } else {
            last_blank = false;
        }

        putchar(c);
    }

    return 0;
}
