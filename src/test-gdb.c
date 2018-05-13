// small broken software to learn gdb debugger

#include <stdio.h>

int * f()
{
    return (int*) 42;
}

void print(int * v) {
    printf("value=%d", *v);
}

int main() {
    print (f());

    return 0;
}
