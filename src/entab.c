/*
Exercise 1-21.
Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a
single blank would suffice to reach a tab stop, which should be given preference?
*/

#include <stdio.h>
#include <stdbool.h>
#include "include/string.h"

#define MAX_LINE_SIZE 200
#define SPACES_IN_TAB 4

char * entab(char * str, char * entabed);

int main() {
    char str[MAX_LINE_SIZE] = { 0 };
    char entabed_str[MAX_LINE_SIZE] = { 0 };

    int line_length = 0;
    while ((line_length = m_getline(str, MAX_LINE_SIZE)) != EOF) {
        entab(str, entabed_str);
        printf("%s\n", entabed_str);
    }

    return 0;
}

char * entab(char * str, char * entabed) {
    bool spaces_stopped = false;
    int total_spaces = 0;
    int total_tabs = 0;
    int i = 0;
    while (true) {
        char c = str[i];
        if (c == '\0') {
            entabed[i - total_spaces + total_tabs] = '\0';
            break;
        }

        if (!spaces_stopped && c == ' ') {
            ++total_spaces;
            if (total_spaces % SPACES_IN_TAB == 0) {
                entabed[total_tabs++] = '\t';
            }
        } else {
            if (!spaces_stopped) {
                spaces_stopped = true;

                if (total_spaces % SPACES_IN_TAB != 0) {
                    entabed[total_tabs++] = '\t';
                }
            }

            entabed[i - total_spaces + total_tabs] = str[i];
        }

        ++i;
    }
}
