#include <stdio.h>
#include "include/hashtable.h"

#define MAX_STR_SIZE 100

int main()
{
    puts("Please input you values: key value");

    char key[MAX_STR_SIZE] = { };
    char value[MAX_STR_SIZE] = { };

    while (scanf("%s %s", key, value) != EOF)
    {
        set_key(key, value);
    }

    puts("Please input keys to get");
    while (scanf("%s", key) != EOF)
    {
        char * value = get_value(key);

        if (value)
        {
            printf("%s: %s\n", key, value);
        }
        else
        {
            printf("Can not find value for key %s\n", key);
        }
    }

    return 0;
}
