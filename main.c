#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[100];
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (buf[i] == '\n') {
                buf[i] = '\0';
            }
        }
        printf("%zu\n", strlen(buf));
        break;
    }
    return 0;
}
