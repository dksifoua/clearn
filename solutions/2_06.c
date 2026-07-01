// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
// position p set to the rightmost n bits of y, leaving the other bits unchanged.

#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void) {
    // unsigned x = 73, p = 4, n = 3;
    // printf("getbits(%d, %d, %d) = %d (4 expected)\n", x, p, n, getbits(x, p, n));

    unsigned x = 204, p = 3, n = 2, y = 170;
    printf("getbits(%d, %d, %d) = %d (200 expected)\n", x, p, n, setbits(x, p, n, y));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    // p = 3
    // n = 2
    // 1100 1100 = x = 4 + 8 + 64 + 128 = 204
    // 1010 1010 = y = 2 + 8 + 32 + 128 = 170
    // 1100 1000 = r = 200

    // 1010 1010 = y
    // 0000 0010 = y & ~(~0 << n)
    // 0000 1000 = y & ~(~0 << n) << (p - n + 1)
    unsigned selected_bits_from_y = (y & ~(~0 << n)) << (p - n + 1);

    // 0000 1100 = ~(~0 << n) << (p - n + 1) = 12
    unsigned cleared_bits_from_x = ~(~0 << n) << (p - n + 1);

    // 1100 0000 = x & ~cleared_bits_from_x = 192
    // 0000 1000 = selected_bits_from_y
    // 1100 1000 = (x & ~cleared_bits_from_x) | selected_bits_from_y
    return (x & ~cleared_bits_from_x) | selected_bits_from_y;
}

unsigned getbits(unsigned x, int p, int n) {
    // 0100 1001 = x = 1 + 8 + 64 = 73
    // 0000 0010 = 2 = res
    // 
    // 0000 0000 = 0
    // 1111 1111 = ~0
    // 1110 0000 = ~0 << (p + 1)
    // 0001 1111 = ~(~0 << (p + 1)) = 1 + 2 + 4 + 8 + 16 = 31
    // 0100 1001 = x
    // 0000 1001 = x & ~(~0 << (p + 1)) = 1 + 8 = 9
    // 0000 0010 = (x & ~(~0 << (p + 1))) >> (p + 1 - n) = 2

    return (x & ~(~0 << (p + 1))) >> (p + 1 - n);
}
