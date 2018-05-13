/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables,
both signed and unsigned, by printing appropriate values from standard headers and by direct
computation. Harder if you compute them: determine the ranges of the various floating-point
types.
*/

#include <stdio.h>

unsigned get_max_unsigned_int() {
    return -1;
}

int get_max_int() {
    int max = 0;

    while (max >= 0) {
        ++max;
    }

    return --max;
}

int get_min_int() {
    return get_max_int() + 1;
}

char get_max_char() {
    char max = 0;
    while (max >= 0) {
        ++max;
    }

    return --max;
}

unsigned char get_max_unsigned_char() {
    return -1;
}

char get_min_char() {
    return get_max_char() + 1;
}

int main() {
    printf("Char: [%d, %d]\n", get_min_char(), get_max_char());
    printf("Unsigned Char: [%u, %u]\n", 0, get_max_unsigned_char());
    printf("Unsigned Int: [%u, %u]\n", 0u, get_max_unsigned_int());
    printf("Signed Int: [%d, %d]\n", get_min_int(), get_max_int());

    return 0;
}
