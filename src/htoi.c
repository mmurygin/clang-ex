/*
Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value.
The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <math.h>
#include "include/string.h"
#include "include/type.h"

#define MAX_LINE_LENGTH 100
#define ZERO_CHAR_TO_INT 48

int htoi(char * str);

int main()
{
    char str[MAX_LINE_LENGTH] = { 0 };
    m_getline(str, MAX_LINE_LENGTH);

    printf("Got line %s\n", str);

    int int_val = htoi(str);

    printf("%s = %d\n", str, int_val);

    return 0;
}

int get_int_from_hex(char c) {
    if (is_digit(c)) {
        return c - ZERO_CHAR_TO_INT;
    }

    switch (c)
    {
        case 'a':
            return 10;
        case 'b':
            return 11;
        case 'c':
            return 12;
        case 'd':
            return 13;
        case 'e':
            return 14;
        case 'f':
            return 15;
        default:
            // indicates error
            return -1;
    }
}

int htoi(char * str) {
    const int len = m_strlen(str);

    int result = 0;

    int i = 0;
    while (i < len) {
        const char c = str[len - 1 - i];

        if (c == 'x' || c == 'X') {
            break;
        }

        const int int_val = get_int_from_hex(c);

        if (int_val == -1) {
            // indicates error
            return -1;
        }

        result += int_val * pow(16, i);
        ++i;
    }

    return result;
}
