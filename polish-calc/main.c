#include <stdio.h>
#include <ctype.h>

#include "include/stack.h"
#include "include/atof.h"
#include "include/io.h"

#define STACK_SIZE 100
#define STR_SIZE 100

#define NUMBER '0'

void calculate();

int main()
{
    char str[STR_SIZE] = { '\0' };
    int op = 0;
    while((op = getop(str, STR_SIZE)) != EOF)
    {
        switch (op)
        {
            case NUMBER:
                printf("Got number: %s\n", str);
                break;
            case '+':
                printf("Got char: %c\n", op);
            default:
                calculate();
                break;
        }
    }

    puts("Done!");

    return 0;
}

void calculate()
{
    puts("Result: ");
}
