// Exercise 4-1. Write the function strindex(s,t) which returns the position of
// the rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>

int strindex(const char s[], const char t[]);

void test(const char s[], const char t[], const int expected) {
    const int actual = strindex(s, t);
    printf("s = %s - t = %s - expected = %d - actual = %d\n", s, t, expected,
           actual);
}

int main(void) {
    test("ababab", "ab", 4);
    test("abcdef", "cd", 2);
    test("abcdef", "ab", 0);
    test("abcdef", "ef", 4);
    test("abcdef", "xyz", -1);
    test("abcdef", "abcdeff", -1);
    test("", "a", -1);
    return 0;
}

int strindex(const char s[], const char t[]) {
    size_t slen = strlen(s), tlen = strlen(t);
    if (tlen > slen) {
        return -1;
    }

    int match_index = -1;
    for (size_t i = 0; i < slen; ++i) {
        size_t j = i, k = 0;
        for (; j < slen && k < tlen && s[j] == t[k]; ++j, ++k)
            ;
        
        if (k == tlen) {
            match_index = i;
        }
    }

    return match_index;
}
