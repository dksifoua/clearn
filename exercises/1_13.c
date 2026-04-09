// Write a program to print a histogram of the lengths of words in its input. It is
// easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. 

#include <stdio.h>

#define MAX_WORD_LENGTH 24
#define SPACE ' '
#define NEW_LINE '\n'
#define TAB '\t'

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int hist[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        hist[i] = 0;
    }
    
    int prev = SPACE, curr = getchar(), wl = 0;
    while (curr != EOF) {
        // Start of a word: curr   | •c    | ->c | <-c
        // Inside of a word
        if (curr != SPACE && curr != TAB && curr != NEW_LINE) wl += 1;
        
        // End of a word:   c•  | c->   | c<-
        else if (
            (curr == SPACE || curr == TAB || curr == NEW_LINE) &&
            (prev != SPACE && prev != TAB && prev != NEW_LINE)
        ) {
            hist[min(wl, MAX_WORD_LENGTH) - 1] += 1;
            wl = 0;
        }
        
        prev = curr;
        curr = getchar();
    }
    
    if (wl > 0) hist[min(wl, MAX_WORD_LENGTH) - 1] += 1;
    
    printf("\n");
    for (int i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("%02d = %02d [", i + 1, hist[i]);
        for (int j = 0; j < MAX_WORD_LENGTH; ++j) {
            if (j < hist[i]) printf("+");
            else printf(" ");
        }
        printf("]\n");
    }
    
    return 0;
}