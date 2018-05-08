#include <stdio.h>

void m_copyline(char * src, char * dst) {
    int i = 0;
    while ((dst[i] = src[i]) != '\0') {
        ++i;
    }
}

int m_getline(char * s, int string_limit) {
    int i = 0;

    char c;
    while ((c = getchar()) != EOF && c != '\n') {
        s[i] = c;

        if (++i == string_limit) {
            break;
        }
    }

    s[i] = '\0';

    return c == EOF ? EOF : i;
}
