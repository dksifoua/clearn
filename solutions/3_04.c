// Exercise 3-4. In a two's complement number representation, our version of
// itoa does not handle the largest negative number, that is, the value of n
// equal to -(2^wordsize-1). Explain why not. Modify it to print that value
// correctly, regardless of the machine on which it runs.
// 
// Because negating -(2^wordsize-1) will overflow.

#include <stdio.h>
#include <string.h>

void itoa(char n, char s[]);
void reverse(char s[]);

int main(void) {
    char s[128];
    char n = -128;
    itoa(n, s);
    printf("n = %d => s = %s\n", n, s);
    return 0;
}

void itoa(const char n, char s[]) {
    char nc = n;
    int i = 0, sign = nc < 0 ? -1 : 1;
    do {
        s[i++] = (nc % 10) * sign + '0';
    } while ((nc /= 10) != 0);
    if (sign < 0) s[i++] = '-';
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
