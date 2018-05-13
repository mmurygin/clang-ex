/*
Write an alternate version of squeeze(s1,s2) that deletes each character in s1 that matches any
character in the string s2.
*/

#include <stdio.h>
#include "include/string.h"

#define MAX_LINE_LENGTH 100

void squeeze(char *s1, const char * s2);

int main()
{
    char str[MAX_LINE_LENGTH] = { 0 };
    const char to_squezee[] = "123";

    while (m_getline(str, MAX_LINE_LENGTH) != -1)
    {
        squeeze(str, to_squezee);
        printf("%s\n", str);
    }

    return 0;
}

void squeeze(char * str_to_squeeze, const char * pattern)
{
    char target[MAX_LINE_LENGTH] = { 0 };

    int matches = 0;
    char current_char;
    int i;
    for (i = 0; (current_char = str_to_squeeze[i]) != '\0'; ++i)
    {
        if (m_strcharindex(pattern, current_char) != -1)
        {
            ++matches;
        }
        else
        {
            target[i - matches] = current_char;
        }
    }

    target[i - matches] = '\0';

    m_strcopy(target, str_to_squeeze);
}
