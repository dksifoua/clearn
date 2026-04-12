// Write a function reverse(s) that reverses the character string s. Use it to
// write a program that reverses its input a line at a time.

#include <stdio.h>

#define MAX_LINE_LENGTH 256

#define BLANK ' '
#define NLINE '\n'
#define ELINE '\0'

int readline(char line[], int maxlen);
void reverse(char line[], int maxlen);

int main(void) {
    char line[MAX_LINE_LENGTH], eof;
    do {
        eof = readline(line, MAX_LINE_LENGTH);
        reverse(line, MAX_LINE_LENGTH);
        for (int i = 0; i < MAX_LINE_LENGTH; ++i) {
            if (line[i] == ELINE) {
                putchar(NLINE);
                break;
            }
            putchar(line[i]);
        }
    } while (eof != EOF);

    return 0;
}

int readline(char line[], int maxlen) {
     char chr;
     int i = 0;
     while (i < maxlen - 1) {
         chr = getchar();
         if (chr == EOF || chr == NLINE) break;

         line[i++] = chr;
     }

     if (i < maxlen) {
         line[i] = ELINE;
         if (chr == EOF) return EOF;
     }

     return 0;
}

 void reverse(char line[], int maxlen) {
     if (line[0] == ELINE) return;

     int i = 0, j = 0;
     while (j < MAX_LINE_LENGTH) {
         if (line[j] == ELINE) break;
         j += 1;
     }

     // J is at ELINE.
     j -= 1;

     char temp;
     while (i < j) {
         temp = line[i];
         line[i] = line[j];
         line[j] = temp;

         i += 1;
         j -= 1;
     }
}
