//  Exercise 1 - 19.
// Write a function reverse(s) that reverses the character string s.Use it to write a program
// that reverses its input a line at a time.

#include <stdio.h>
#include "include/string.h"

#define MAX_LINE_LENGTH 100

int main() {
    char s[MAX_LINE_LENGTH] = { 0 };

    int line_length = 0;
    while ((line_length = m_getline(s, MAX_LINE_LENGTH)) != EOF) {
        m_reverse(s);
        printf("%s\n", s);
    }

    return 0;
}
