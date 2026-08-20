// Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations
// like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
// Allow for letters of either case and digits, and be prepared to handle cases
// like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
// literally.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define and &&
#define or ||

void expand(const char s1[], char s2[]);
bool is_valid_range(const char left, const char right);

void test(const char in[]) {
    char out[128];
    expand(in, out);
    printf("[%s] => [%s]\n", in, out);
}

int main(void) {
    test("");
    test("-");
    test("hello");
    test("a-zA-Z0-9-");
    test("a-zZ-A0-9-");
    test("-a-dG-K3-6");
    test("a-b-c");
    test("a-a");
    test("a-A");
    return 0;
}

void expand(const char in[], char out[]) {
    size_t in_len = strlen(in), j = 0;
    for (size_t i = 0; i < in_len; ++i) {
        if (i == 0 or i == in_len - 1 or in[i] != '-') {
            out[j++] = in[i];
            continue;
        }

        char left = in[i - 1], right = in[i + 1];
        if (is_valid_range(left, right)) {
            while (++left < right) {
                out[j++] = left;
            }
        } else {
            out[j++] = '-';
        }
    }

    out[j] = '\0';
}

bool is_valid_range(const char left, const char right) {
    if (left >= right)
        return false;
    if (left >= 'a' and left <= 'z' and right >= 'a' and right <= 'z')
        return true;
    if (left >= 'A' and left <= 'Z' and right >= 'A' and right <= 'Z')
        return true;
    if (left >= '0' and left <= '9' and right >= '0' and right <= '9')
        return true;

    return false;
}
