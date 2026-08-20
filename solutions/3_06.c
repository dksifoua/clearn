// Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
// argument is a minimum field width; the converted number must be padded with blanks on the
// left if necessary to make it wide enough.

#include <stdio.h>
#include <string.h>

void itoa(char n, char s[], unsigned w);
void reverse(char s[]);

int main(void) {
    char s[128];
    char n = -128;
    itoa(n, s, 5);
    printf("n = [%d] => s = [%s]\n", n, s);
    return 0;
}

void itoa(const char n, char s[], unsigned w) {
    char nc = n;
    int i = 0, sign = nc < 0 ? -1 : 1;
    do {
        s[i++] = (nc % 10) * sign + '0';
    } while ((nc /= 10) != 0);

    while (i < w) {
        if (sign < 0 && i == w - 1) s[i++] = '-';
        else s[i++] = '0';
    }
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
