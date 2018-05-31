#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100
#define NUMBER '0'

char buffer[BUFFER_SIZE] = { };
int buf_pointer = 0;

char getch()
{
    if (buf_pointer > 0)
    {
        return buffer[--buf_pointer];
    }

    return getchar();
}

void ungetch (char c)
{
    buffer[buf_pointer++] = c;
}

int getop(char * str, int limit)
{
    char c;
    int i = 0;
    while (((c = getch()) != ' ' && c != '\t' || i == 0) && i < limit)
    {
        if (isdigit(c))
        {
            str[i++] = c;
        } else if (i == 0) {
            return c;
        } else {
            ungetch(c);
            break;
        }
    }

    str[i++] = '\0';
    return NUMBER;
}
