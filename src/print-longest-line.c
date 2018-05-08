// prints the longest line in input

#include <stdio.h>
#include "include/string.h"

#define MAX_LINE_SIZE 100

int main() {
    char line [MAX_LINE_SIZE + 1] = {0};
    char max_line [MAX_LINE_SIZE + 1] = {0};

    int max_length = 0;
    int line_length = 0;
    while ((line_length = m_getline(line, MAX_LINE_SIZE)) != EOF) {
        if (line_length > max_length) {
            max_length = line_length;
            m_copyline(line, max_line);
        }
    }

    printf("%s\n", max_line);

    return 0;
}
