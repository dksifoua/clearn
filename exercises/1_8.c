// Write a program to count blanks, tabs, and newlines.

#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'


int main() {
    int nb = 0, nt = 0, nl = 0;

    int c;
    while ((c = getchar()) != EOF) {
        if (c == BLANK) {
            nb += 1;
            continue;
        }

        if (c == TAB) {
            nt += 1;
            continue;
        }

        if (c == NEWLINE) {
            nl += 1;
        }
    }
    printf("\n");
    printf("# of blanks:\t\t%03d\n", nb);
    printf("# of tabs:\t\t%03d\n", nt);
    printf("# of new lines:\t\t%03d\n", nl);

    return 0;
}
