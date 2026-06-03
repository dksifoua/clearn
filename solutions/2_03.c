// Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits
// (including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
// through 9, a through f, and A through F.

#include <stdio.h>

int htoi(const char s[]);

int main(void) {
    printf("2F3 = %d\n", htoi("2F3"));
    printf("0x2F3 = %d\n", htoi("0x2F3"));
    printf("0X2F3 = %d\n", htoi("0X2F3"));
    
    return 0;
}

int htoi(const char s[]) {
    int result = 0, i = 0;
    
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    while (s[i] != '\0') {
        int value;
        if ('0' <= s[i] && s[i] <= '9') {
            value = s[i] - '0';
        } else if ('a' <= s[i] && s[i] <= 'f') {
            value = s[i] - 'a' + 10;
        } else if ('A' <= s[i] && s[i] <= 'F') {
            value = s[i] - 'A' + 10;
        } else {
            break;
        }

        result = (result * 16) + value;
        i += 1;
    }
    
    return result;
}
