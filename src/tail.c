#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void tail(int n);

int main(int argc, char const *argv[])
{
    int n = 10;
    for (int i = 1; i < argc - 1; i++)
    {
        if (strcmp(argv[i], "-n\0") == 0)
        {
            n = atoi(argv[i+1]);
        }
    }

    tail(n);

    return 0;
}

void tail (int n)
{
    printf("n = %d\n", n);
}
