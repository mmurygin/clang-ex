#include <stdio.h>
#include "include/alloc.h"

int main()
{
    char * s1 = alloc(100);
    char * s2 = alloc(200);
    char * s3 = alloc(300);

    printf("%p %p %p\n", s1, s2, s3);

    afree(s3);
    afree(s2);
    afree(s1);

    return 0;
}
