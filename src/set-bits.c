/*
Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p set
to the rightmost n bits of y, leaving the other bits unchanged.
*/

#include <stdio.h>

unsigned setbits (unsigned x, unsigned p, unsigned n, unsigned y)
{
    return x;
}

int main()
{
    unsigned result = setbits(157, 4, 3, 122);
    unsigned expect_result = 137;
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
