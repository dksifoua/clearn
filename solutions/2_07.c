// Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
// position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged. 

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
    // 1011 0010 = x = 2 + 16 + 32 + 128 = 178
    // 1000 1110 = r = 128 + 8 + 4 + 2 = 142
    unsigned x = 0b10110010, r = 0b10001110;
    int p = 5, n = 4;
    printf("invert(%u, %d, %d) = %u (Expected = %u)\n", x, p, n, invert(x, p, n), r);
    return 0;
}

unsigned invert(unsigned x, int p, int n) {
    // 1011 0010 = x
    // 0011 1100 = mask = 4 + 8 + 16 + 32 = 60
    // 1100 1110 = r
    unsigned mask = ~(~0u << n) << (p - n + 1);
    return x ^ mask; // 
}
