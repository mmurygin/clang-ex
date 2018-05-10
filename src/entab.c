/*
Exercise 1-21.
Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks
to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a
single blank would suffice to reach a tab stop, which should be given preference?
*/

#include <stdio.h>
#include "include/string.h"

#define MAX_LINE_SIZE 200
#define SPACES_IN_TAB 4

void entab(char * str);

int main() {
    char str[MAX_LINE_SIZE] = { 0 };

    int line_length = 0;
    while ((line_length = m_getline(str, MAX_LINE_SIZE)) != EOF) {
        entab(str);
        printf("%s\n", str);
    }

    return 0;
}

void entab(char * str) {

}
