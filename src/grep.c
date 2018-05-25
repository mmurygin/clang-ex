#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#define SEARCH_PATTERN "has"

int strindex(const char * str, const char * pattern);

int main() {
    char *buffer = NULL;
    size_t len = 0;
    ssize_t read;
    while (getline(&buffer, &len, stdin) != EOF)
    {
        if (strindex(buffer, SEARCH_PATTERN) != -1)
        {
            puts(buffer);
        }

        free(buffer);
        buffer = NULL;
    }

    return 0;
}

int strindex(const char *str, const char *pattern)
{
    for (int str_i = 0; str[str_i] != '\0'; ++str_i)
    {
        for (int pattern_i = 0; str[str_i + pattern_i] != '\0'; ++pattern_i)
        {
            if (pattern[pattern_i] == '\0')
            {
                return str_i;
            }

            if (str[str_i + pattern_i] != pattern[pattern_i])
            {
                break;
            }
        }
    }

    return -1;
}
