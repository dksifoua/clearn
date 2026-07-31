// Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
// in x. Explain why. Use this observation to write a faster version of bitcount. 
// 
// If the last bit of x is 1, then the last bit of x - 1 will be 0
// If the last bit of x is 0, then the last bit of x - 1 will be 1
// x & (x - 1) = 1 & 0 = 0 & 1 = 0

#include <stdio.h>

int bitcount(unsigned x);
int tobinary(unsigned x);

int main(void) {
    unsigned x = 12;
    printf("bitcount(%d) = %d\n", x, bitcount(x));
    return 0;
}

int bitcount(unsigned x) {
    int nbits;
    for (nbits = 0; x != 0; x &= x - 1) {
        ++nbits;
    }
    return nbits;
}

int tobinary(unsigned x) {
    // x = 7
    // 7 % 2 = 1 | 7 / 2 = 3 | x100
    // 3 % 2 = 1 | 3 / 2 = 1 | x10
    // 1 % 2 = 1 | 1 / 2 = 0 | x1
    int res = 0;
    while (x > 0) {
        res = res * 1e()
        x /= 2;
    }
    return res;
}
