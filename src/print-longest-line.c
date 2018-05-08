#include <stdio.h>

#define MAX_LINE_SIZE 100

int m_getline(char * s, int string_limit);
void m_copyline(char * src, char * dst);

int main() {
    char line [MAX_LINE_SIZE + 1] = {0};
    char max_line [MAX_LINE_SIZE + 1] = {0};

    int max_length = 0;
    int line_length = 0;
    while ((line_length = m_getline(line, MAX_LINE_SIZE)) != 0) {
        if (line_length > max_length) {
            max_length = line_length;
            m_copyline(line, max_line);
        }
    }

    printf("%s\n", max_line);

    return 0;
}

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

    return i;
}
