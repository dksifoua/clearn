#include <stdio.h>

int main(void) {
    int w, h, n;
    if ((n = scanf("%d %d", &w, &h)) != 2) {
        return -1;
    }
    printf("%d\n", w * h);
    return 0;
}
