#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    printf("The total number of arguments: %d\n", argc);

    printf("Integer value: %d\n", atoi(argv[1]));

    return 0;
}
