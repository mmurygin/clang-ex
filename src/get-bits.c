#include <stdio.h>

void print_bits(unsigned int x)
{
    int i;
    for (i = 8 * sizeof(x) - 1; i >= 0; i--)
    {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

unsigned get_bits(unsigned value, unsigned from, unsigned to)
{
    printf("value >> from ");
    print_bits(value >> from);
    return (value >> from) & ~(~0 << (to - from + 1));
}

int main()
{
    puts("Pleas input value from to:");

    unsigned value, from, to;
    while (scanf("%u %u %u", &value, &from, &to) != EOF)
    {
        printf("Input:\nvalue:  ");
        print_bits(value);
        printf("from: %u\nto: %u\n", from, to);

        printf("Result: ");
        print_bits(get_bits(value, from, to));
    }

    return 0;
}
