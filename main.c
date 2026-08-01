#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) {
        return -1;
    }
    getchar();

    FILE *out = fopen("/tmp/clines.txt", "w");
    if (out == NULL) {
        return -1;
    }
    
    char buf[1024];
    for (int i = 0; i < n; i++) {
        if (fgets(buf, sizeof(buf), stdin) != NULL) {
            fprintf(out, "%s", buf);
        }
    }
    fclose(out);

    FILE *in = fopen("/tmp/clines.txt", "r");
    if (in == NULL) {
        return -1;
    }

    int nlines = 0;
    while (fgets(buf, sizeof(buf), in) != NULL) {
        nlines += 1;
    }
    fclose(in);

    printf("lines: %d\n", nlines);
    return 0;
}
