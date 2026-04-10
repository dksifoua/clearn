// Read a set of text lines and prints the longest. 

#include <stdio.h>

#define MAX_LINE_LENGTH 256
#define NEW_LINE '\n'
#define EOL '\0'

int endoffile = 0;

/*
 * Read line from stdin.
 * Line ends with EOL.
 * Return the length of the line.
 */
int readline(char line[], int maxlen);

/*
 * Copy the source line into target line.
 */
void copy(char source[], char target[]);

int main() {
    char longestline[MAX_LINE_LENGTH], currentline[MAX_LINE_LENGTH];
    int nlongestline = 0, ncurrentline;
    while (!endoffile) {
        ncurrentline = readline(currentline, MAX_LINE_LENGTH);
        if (ncurrentline > nlongestline) {
            copy(currentline, longestline);
            nlongestline = ncurrentline;
        }
    }
    
    printf("\n\nLongest line (%d): %s\n", nlongestline, longestline);
    return 0;
}

int readline(char line[], int maxlen) {
    int character, ncharacter = 0;
    while ((character = getchar()) != NEW_LINE && character != EOF) {
        if (ncharacter < maxlen - 1)
            line[ncharacter++] = character;
    }
    
    if (character == EOF)
        endoffile = 1;
    
    line[ncharacter] = EOL;
    return ncharacter;
}

void copy(char source[], char target[]) {
    for (int i = 0; i < MAX_LINE_LENGTH; ++i) {
        target[i] = source[i];
        if (source[i] == EOL)
            break;
    }
}