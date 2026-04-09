#include <stdio.h>

#define SPACE ' '
#define NLINE '\n'
#define TAB '\t'

int char_count() {
    int cc;
    for (cc = 0; getchar() != EOF; cc += 1)
        ;
    
    return cc;
}

int line_count() {
    int c, lc = 0;
    while ((c = getchar()) != EOF) {
        if (lc == 0 || c == NLINE) {
            lc += 1;
        }
    }
    
    return lc;
}

void replace_multiple_spaces() {
    int prevc, currc = getchar();
    putchar(NLINE);
    while (currc != EOF) {
        if (!(prevc == currc && currc == SPACE)) {
            putchar(currc);
        }
        
        prevc = currc;
        currc = getchar();
    }
    printf("\n");
}

int main() {
    printf("Enter text:\n");
    // int cc = char_count();
    // int lc = line_count();
    
    // printf("You entered %d characters.\n", cc);
    // printf("You entered %d lines.\n", lc);
    replace_multiple_spaces();
    return 0;
}