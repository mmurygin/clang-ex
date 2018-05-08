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

int m_strlen(char * str) {
    int i = 0;

    while (str[i] != '\0') {
        ++i;
    }

    return i;
}

int m_reverse(char * str) {
    int len = m_strlen(str);

    char other[len + 1];

    m_copyline(str, other);

    for (int i = 0; i < len; i++) {
        str[i] = other[len - i - 1];
    }
}
