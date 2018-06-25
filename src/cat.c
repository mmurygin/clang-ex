#include <stdio.h>
#include "include/error.h"

void print_file(const char *file_name);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        print_file(argv[i]);
    }

    return 0;
}

void print_file(const char *file_name)
{
    FILE *src = fopen(file_name, "r");

    if (!src)
    {
        error("Can not open file %s", file_name);
    }

    int c;
    while ((c = fgetc(src)) != EOF)
    {
        putchar(c);
    }

    fclose(src);
}
