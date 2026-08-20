// Exercise 3-2. Write a function escape(s,t) that converts characters like
// newline and tab into visible escape sequences like \n and \t as it copies the
// string t to s. Use a switch. Write a function for the other direction as
// well, converting escape sequences into the real characters.

#include <stddef.h>
#include <stdio.h>

void escape(char s[], const char t[]);

int main(void) {
    char in[] = "Hello\t\t\n\nA\tB\nCA\\B";
    char out[128];
    escape(out, in);
    printf("in  = [%s]\n", in);
    printf("out = [%s]\n", out);
    return 0;
}

void escape(char out[], const char in[])  {
    size_t i = 0, j = 0;
    char c;
    while ((c = in[i++]) != '\0') {
        switch (c) {
            case '\t':
                out[j++] = '\\';
                out[j++] = 't';
                break;
            case '\n':
                out[j++] = '\\';
                out[j++] = 'n';
                break;
            default:
                out[j++] = c;
                break;
        }
    }

    out[j] = '\0';
}
