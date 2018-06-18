#include <stdio.h>

int main(int argc, char const *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");

        int c;
        while ((c = fgetc(fp)) != EOF)
        {
            putchar(c);
        }

        fclose(fp);
    }

    return 0;
}
