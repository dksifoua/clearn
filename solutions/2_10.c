// Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
// with a conditional expression instead of if-else. 

#include <stdio.h>

void lower(char buf[]);

int main(void) {
    char buf[] = "Exercise 2-10. Rewrite the FUNCTION lower, which CONVERTS upper case letters to lower case.";
    printf("%s\n", buf);
    lower(buf);
    printf("%s\n", buf);
    return 0;
}

void lower(char buf[]) {
    for (int i = 0; buf[i] != '\0'; ++i) {
        if (buf[i] >= 'A' && buf[i] <= 'Z') {
            buf[i] = 'a' + buf[i] - 'A';
        }
    }
}
