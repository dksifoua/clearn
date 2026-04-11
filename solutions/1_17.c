// Write a program to print all input lines that are longer than 80 characters.

#include <stdio.h>

#define MIN_LINE_LENGTH 80
#define NEW_LINE '\n'

int main() {
    int line[MIN_LINE_LENGTH] = { 0 }, chr, i = 0;
    while ((chr = getchar()) != EOF) {
        if (chr == NEW_LINE) {
            i = 0;
            continue;
        }
        
        if (i < MIN_LINE_LENGTH) {
            line[i++] = chr;
        }
        
        if (i == MIN_LINE_LENGTH) {
            putchar(NEW_LINE);
            for (int j = 0; j < MIN_LINE_LENGTH; ++j) {
                putchar(line[j]);
            }
            
            while ((chr = getchar()) != NEW_LINE && chr != EOF) {
                putchar(chr);
            }
            
            i = 0;
        }
    }
    putchar(NEW_LINE);
    
    return 0;
}