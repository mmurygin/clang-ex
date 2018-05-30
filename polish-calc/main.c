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
    init_stack(STACK_SIZE);

    char str[STR_SIZE] = { '\0' };
    int op = 0;
    while((op = getop(str, STR_SIZE)) != EOF)
    {
        double op1, op2;
        switch (op)
        {
            case NUMBER:
                push(atof(str));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op1 = pop();
                op2 = pop();
                push(op2 - op1);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op1 = pop();
                op2 = pop();
                push(op2 / op1);
                break;
            default:
                printf("Result: %.2f\n", pop());
                break;
        }
    }

    return 0;
}
