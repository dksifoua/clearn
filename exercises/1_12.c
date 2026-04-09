// Write a program that prints its input one word per line. 

#include <stdio.h>

#define SPACE ' '
#define TAB '\t'
#define NEW_LINE '\n'

int main() {
    int p = 0, c = getchar();
    printf("\n");
    while (c != EOF) {        
        // Word: c | •c | ->c | <-c
        if (
            (c != SPACE  && c != TAB && c != NEW_LINE) &&
            (p == SPACE  || p == TAB || p == NEW_LINE)
        ) putchar(NEW_LINE);
        
        putchar(c); 
        
        p = c;
        c = getchar();
    }
    
    printf("\n");
    
    return 0;
}