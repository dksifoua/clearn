#include <stdio.h>

int main(void) {
    int a, b;
    int n = scanf("%d %d", &a, &b);
    if (n != 2) {
        printf("Error while reading from stdin.\n");
        return 1;
    }

    printf("%d\n", a + b);
    return 0;
}
