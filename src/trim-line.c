// Write a program to remove trailing blanks and tabs from each line of input,
// and to delete entirely blank lines.

#include <stdio.h>
#include <stdbool.h>
#include "include/string.h"

#define MAX_LINE_LENGTH 100

int main() {
    char s[MAX_LINE_LENGTH] = { 0 };

    int line_length = 0;
    while ((line_length = m_getline(s, MAX_LINE_LENGTH)) != EOF) {
        if (line_length) {
            bool need_trim = true;
            char c = 0;
            for (int i = 0; (c = s[i]) != '\0'; ++i) {
                if (need_trim && (c == ' ' || c == '\t')) {
                    continue;
                }

                need_trim = false;
                putchar(c);
            }

            putchar('\n');
        }
    }

    return 0;
}
