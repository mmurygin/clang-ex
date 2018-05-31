/*
Suppose we have  identical-looking boxes each containing a drone ready to ship,
but we remember that one box is missing instructions!

“Open up all the boxes!” said the man in charge. One employee had a better idea.
He realized that the box without the instructions would weigh a little less than the rest,
and there happened to be a (very large) balance scale in the back room that could compare the
weights of any two seperate groups of boxes.

Assuming the worst case scenario, what is the minimum number of weighings needed to determine
which box has the missing instructions?
*/

#include <stdio.h>
#include <math.h>

int weights_count(int n);

int main()
{
    int n;
    puts("Please enter the number of boxes:");
    scanf("%d", &n);

    printf("The result: %d\n", weights_count(n));

    return 0;
}

int weights_count(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2 || n == 3)
    {
        return 1;
    }
    else
    {
        return weights_count(ceil(n / 3)) + 1;
    }
}
