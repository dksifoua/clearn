// Write a program to remove trailing blanks and tabs from each line of input, and
// to delete entirely blank lines.

#include <stdio.h>

#define SPACE ' '
#define NEW_LINE '\n'
#define TAB '\t'

int display_result = 1;

int readline();

int main() {
    int eof;
    while ((eof = readline()) != EOF);
    putchar(NEW_LINE);
    return 0;
}

int readline() {    
    int p, c;
    while ((p = getchar()) != NEW_LINE) {
        if (display_result) {
            printf("\n================== Result ==================\n");
            display_result = 0;
        }
        
        if (p == EOF) return EOF;
        if (p != SPACE && p != TAB) {
            putchar(p);
            break;
        }
    }
    if (p == NEW_LINE) return 0;
    
    while ((c = getchar()) != NEW_LINE) {
        if (c == EOF) return EOF;
        if (c != SPACE && c != TAB) {
            if (p == SPACE || p == TAB) putchar(p);
            putchar(c);
        }
        
        p = c;
    }
    if (c == NEW_LINE) putchar(NEW_LINE);
    
    return 0;
}