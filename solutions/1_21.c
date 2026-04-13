// Write a program entab that replaces strings of blanks by the minimum number
// of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
// either a tab or a single blank would suffice to reach a tab stop, which should be given
// preference?

#include <stdio.h>

#define NTABS 8

#define SPACE ' '
#define TAB '\t'
#define NLINE '\n'

int entabline(void);
int flushspaces(int nspaces, int nputs);

int main(void) {
    int eof;
    while ((eof = entabline()) != EOF);
    return 0;
}
 
int entabline(void) {
    int c, nputs = 0, nspaces = 0;
    while ((c = getchar()) != NLINE) {
        if (c == EOF) break;
        if (c == SPACE) nspaces += 1;
        else {
            nputs = flushspaces(nspaces, nputs);
            nspaces = 0;
            
            putchar(c);
            nputs += 1;
        }
    }
    
    flushspaces(nspaces, nputs);
    if (c == NLINE) putchar(NLINE);
    
    return 0;
}

int flushspaces(int nspaces, int nputs) {
    int nextstop;
    while (nspaces > 0) {
        nextstop = NTABS - (nputs % NTABS);
        if (nspaces >= nextstop && nextstop > 1) {
            putchar(TAB);
            nspaces -= nextstop;
            nputs += nextstop;
        } else {
            putchar(SPACE);
            nspaces -= 1;
            nputs += 1;
        }
    }
    return nputs;
}
