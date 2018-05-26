#include <stdio.h>
#include "include/stack.h"

int main()
{
    int result;
    int val;
    while ((result = scanf("%d", &val)) != EOF)
    {
        printf("%d\n", val);
    }

    return 0;
}
