#include <stdio.h>

int main(void) {
    int numbers[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &numbers[i]);
    }

    int largest = 1 << (sizeof((int) 0) * 8 - 1);
    for (int i = 0; i < 5; ++i) {
        if (largest < numbers[i]) {
            largest = numbers[i];
        }
    }

    printf("%d\n", largest);
    return 0;
}
