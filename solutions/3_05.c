// Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
// a base b character representation in the string s. In particular,
// itob(n,s,16) formats s as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

void itob(const unsigned n, char s[], unsigned char b);
void reverse(char s[]);

void test(unsigned n, unsigned char b) {
    char s[128];
    itob(n, s, b);
    printf("%d base %d = %s\n", n, b, s);
}

int main(void) {
    test(255, 2);
    test(255, 8);
    test(255, 10);
    test(255, 16);
    return 0;
}

void itob(const unsigned n, char s[], unsigned char b) {
    unsigned t = n;
    size_t i = 0;
    do {
        int r = t % b;
        s[i++] = r > 9 ? r - 10 + 'A' : r + '0';
    } while ((t /= b) != 0);
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    size_t i = 0, j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i += 1;
        j -= 1;
    }
}
