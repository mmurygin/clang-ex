/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/

#include <stdio.h>

unsigned invertbits(unsigned x, unsigned p, unsigned n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}

int main()
{
    unsigned result = invertbits(141, 4, 3);
    unsigned expect_result = 145;
    if (result != expect_result)
    {
        printf("Error: %u != %u\n", result, expect_result);
        return 1;
    }
    else
    {
        printf("success\n");
        return 0;
    }
}
