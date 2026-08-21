// Exercise 4-2. Extend atof to handle scientific notation of the form
//  123.45e-6
// where a floating-point number may be followed by e or E and an optionally
// signed exponent.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double atof(const char s[]);

void test(const char in[], const double expected) {
    printf("in = [%s] - Expected = [%f] - Actual = [%f]\n\n", in, expected,
           atof(in));
}

int main(void) {
    test("123.45e6", 123450000.0);
    test("123.45e+6", 123450000.0);
    test("1.23E4", 12300.0);
    test("123.45e-6", 0.00012345);
    test("1e-3", 1e-3);
    test("5e3", 5000.0);
    test("5e+3", 5000.0);
    test("-123.45e2", -12345.0);
    test("-1.23e-2", -0.0123);
    test("123.45", 123.45);
    test("-123.45", -123.45);
    test("0", 0.0);
    test("   123.45e2", 12345.0);
    test("1.0e0", 1.0);
    return 0;
}

double atof(const char s[]) {
    size_t i = 0;
    while (s[i] == ' ' && s[i] == '\t') {
        i += 1;
    }

    int sign = 1;
    if (s[i] == '-') {
        sign = -1;
        i += 1;
    } else if (s[i] == '+') {
        i += 1;
    }

    double val = 0.0;
    while (s[i] >= '0' && s[i] <= '9') {
        val = val * 10.0 + (s[i] - '0');
        i += 1;
    }

    double power = 1.0;
    if (s[i] == '.') {
        i += 1;
        
        while (s[i] >= '0' && s[i] <= '9') {
            val = val * 10.0 + (s[i] - '0');
            power *= 10.0;
            i += 1;
        }
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i += 1;

        int exp_sign = 1;
        if (s[i] == '-') {
            exp_sign = -1;
            i += 1;
        } else if (s[i] == '+') {
            i += 1;
        }

        int exp_val = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            exp_val = exp_val * 10 + (s[i] - '0');
            i += 1;
        }

        for (int j = 0; j < exp_val; j++) {
            if (exp_sign == 1) {
                power /= 10.0;
            } else {
                power *= 10.0;
            }
        }
    }

    return sign * (val / power);
}
