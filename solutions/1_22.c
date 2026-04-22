// Write a program to ``fold'' long input lines into two or more shorter lines after
// the last non-blank character that occurs before the n-th column of input. Make sure your
// program does something intelligent with very long lines, and if there are no blanks or tabs
// before the specified column

#include <stdio.h>

#define ML 20           /* Max line width */
#define BS (ML + 1)     /* BUffer size */

#define SP ' '          /* Space */
#define NL '\n'         /* New line */
#define TB '\t'         /* Tab */
#define ZC '\0'         /* Zero char */

int eof_flag = 0;

int fill(int buffer[], int size, int start);
void foldprint(int buffer[], int size, int pos);
int shift(int buffer[], int size, int pos);

int main(void) {
    int pos, buffer[BS], start = 0;
    while (!eof_flag) {
        pos = fill(buffer, BS, start);
        foldprint(buffer, ML, pos);
        start = shift(buffer, BS, pos);
    }
    return 0;
}

int shift(int buffer[], int size, int pos) {
    int i = 0, j = pos < 0 ? size - 1 : pos + 1;
    while (i < j && j < size && buffer[j] != ZC) {        
        buffer[i++] = buffer[j++];
    }
    
    return i;
}

void foldprint(int buffer[], int size, int pos) {
    int i = 0, j = pos < 0 ? size : pos;
    while (i < j && buffer[i] != ZC) {
        putchar(buffer[i++]);
    }
    
    if (i > 0) putchar(NL);
}

int fill(int buffer[], int size, int start) {
    int i = start, chr, pos = -1;
    while (i < size) {
        chr = getchar();
        if (chr == EOF) {
            eof_flag = 1;
            break;
        }
        if (chr == NL) {
            break;
        }
        if (chr == SP || chr == TB) {
            pos = i;
        }
        
        buffer[i++] = chr;
    }
    
    if (i < size) {
        buffer[i] = ZC;
        pos = size;
    }
    
    return pos;
}
