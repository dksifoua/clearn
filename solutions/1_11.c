// How would you test the word count program? What kinds of input are most
// likely to uncover bugs if there are any?
// 
// Testing Strategy & Key Test Cases:
// No Input (Empty File): Ensures the program returns 0 words, 0 lines, 0 characters.
// No Newlines: Tests if the program handles a file that ends without a \n character correctly.
// Multiple Spaces/Tabs/Newlines: Tests if consecutive white space is handled correctly as a single delimiter between words, not as multiple words.
// Enormous Words: Ensures the program doesn't fail on words longer than a typical buffer.
// Words with Special Characters: Test cases like John's or 123-abc to verify if the program defines these as one word or splits them based on the criteria (e.g., "a sequence of letters, digits, and apostrophes").
// Boundary Conditions: Testing with maximum integer sizes for word/line counts. 

#include <stdio.h>

#define SPACE ' '
#define TAB '\t'
#define NEW_LINE '\n'

int main() {
    int nl, nw, nc;
    nl = nw = nc = 0;
    
    int p = 0, c = getchar();
    while (c != EOF) {
        nc += 1;
        
        if (nl == 0 || c == NEW_LINE) nl += 1;
        
        // Word: c | •c | ->c | <-c
        if (
            nw == 0 ||
            (c != SPACE  && c != TAB && c != NEW_LINE) &&
            (p == SPACE  || p == TAB || p == NEW_LINE)
        ) nw += 1;
        
        p = c;
        c = getchar();
    }
    
    printf("\n");
    printf("Line:\t%03d\n", nl);
    printf("Word:\t%03d\n", nw);
    printf("Char:\t%03d\n", nc);
    
    return 0;
}