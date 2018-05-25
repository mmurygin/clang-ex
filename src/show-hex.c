#include <stdio.h>

int main()
{
    int i;
    puts("Please enter value: ");
    scanf("%d", &i);

    printf("Hex value for %d = %8X\n", i, i);

    return 0;
}
