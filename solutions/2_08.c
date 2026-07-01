// Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
// to the right by n positions.

#include <stdio.h>

unsigned char rightrot(unsigned char x, int n);
int char_wordlength(void);

int main(void) {
    // n = 3
    // 0100 1011 = x = 1 + 2 + 8 + 64 = 75
    // 0110 1001 = r = 1 + 8 + 32 + 64 = 105
    int n = 3;
    unsigned char x = 0b01001011, r = 0b01101001;
    printf("rightrot(%u, %d) = %u (%u expected)\n", x, n, rightrot(x, n), r);
    return 0;
}

unsigned char rightrot(unsigned char x, int n) {
    // 0100 1011 = x
    // 0000 1001 = x >> n = 9
    // 0000 0111 = (1u << n) - 1 = right_mask = 7
    // 0000 0011 = x & ~(~0 << n) = 3
    // 0110 0000 = 96 = x_right_bits
    // 0000 1001 = x >> n = 9
    // 0110 1001 = r = 105
    int bitcount = char_wordlength();
    n %= bitcount;
    unsigned char mask = (1u << n) - 1;
    unsigned char rightbits = x & mask;
    unsigned char leftbits = rightbits << (bitcount - n);
    return (x >> n) | leftbits;
}

int char_wordlength(void) {
    int count = 1;
    unsigned char bits = (unsigned char) ~0u;
    while ((bits >>= 1) > 0) {
        count += 1;
    }
    return count;
}
