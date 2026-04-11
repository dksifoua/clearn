// Write a program to print a histogram of the frequencies of different characters
// in its input.

#include <stdio.h>

#define N_CHARACTERS 256

int main() {
    int hist[N_CHARACTERS] = { 0 };
    
    int c;
    while ((c = getchar()) != EOF) {
        hist[c - 0] += 1;
    }
    
    printf("\n");
    for (int c = 0; c < N_CHARACTERS; ++c) {
        if (c == ' ' || c >= 'a' && c <= 'z') {
            printf("%03d [ %c ] = %03d ", c, c, hist[c]);
            for (int j = 0; j < hist[c]; ++j) {
                printf("•");
            }
            printf("\n");
        }
    }
    
    return 0;
}