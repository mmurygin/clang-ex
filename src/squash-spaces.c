// squashes spacces

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
