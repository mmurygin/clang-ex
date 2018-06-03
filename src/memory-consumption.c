#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100000000

int main()
{
    int *x;

    if ((x = (int *)malloc(sizeof(int) * ARRAY_SIZE)) == NULL)
    {
        printf("memory allocation failure.\n");
        return 1;
    }

    puts("Memory allocation successfull\n");
    long i = ARRAY_SIZE;
    while (1)
    {
        if (i < 0)
        {
            i = ARRAY_SIZE;
        }

        putchar(x[--i] + 48);
    }

    free(x);

    return 0;
}
