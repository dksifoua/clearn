// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
// Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define NTAB 8

#define BLANK ' '
#define TAB '\t'
#define NLINE '\n'

int detabline(void);

int main(void) {
    int eof;
    while ((eof = detabline()) != EOF);
    
    return 0;
}

int detabline(void) {
    int i = 0, c;
    while ((c = getchar()) != NLINE) {
        if (c == EOF) return EOF;
        
        if (c != TAB) {
            putchar(c);
            i = (i + 1) % NTAB;
        } else {
            for(int j = 0; j < NTAB - i; ++j) putchar(BLANK);
            i = 0;
        }
    }
    
    putchar(NLINE);
    
    return 0;
}
