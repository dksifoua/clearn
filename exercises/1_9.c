// Write a program to copy its input to its output, replacing each string of one or
// more blanks by a single blank.

#include <stdio.h>

#define SPACE ' '

int main() {
    int prev = 0, curr = getchar();
    printf("\n");
    while (curr != EOF) {
        if (curr != SPACE || curr != prev) {
            putchar(curr);
        }

        prev = curr;
        curr = getchar();
    }
    printf("\n");
    return 0;
}
