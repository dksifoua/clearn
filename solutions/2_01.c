// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    printf("======================== Ranges from standard headers =================\n");
    printf("%25s: [%20d, %20d]\n", "(signed) char", CHAR_MIN, CHAR_MAX);
    printf("%25s: [%20d, %20d]\n", "unsigned char", 0, UCHAR_MAX);
    printf("%25s: [%20d, %20d]\n", "(signed) short (int)", SHRT_MIN, SHRT_MAX);
    printf("%25s: [%20d, %20u]\n", "unsigned short (int)", 0, USHRT_MAX);
    printf("%25s: [%20d, %20d]\n", "(signed) int", INT_MIN, INT_MAX);
    printf("%25s: [%20d, %20u]\n", "unsigned int", 0, UINT_MAX);
    printf("%25s: [%20ld, %20ld]\n", "(signed) long (int)", LONG_MIN, LONG_MAX);
    printf("%25s: [%20ld, %20lu]\n", "unsigned long (int)", 0L, ULONG_MAX);
    printf("%25s: [%20lld, %20lld]\n", "(signed) long long (int)", LLONG_MIN, LLONG_MAX);
    printf("%25s: [%20lld, %20llu]\n", "unsigned long long (int)", 0LL, ULLONG_MAX);
    printf("%25s: [%20E, %20E]\n", "float", FLT_MIN, FLT_MAX);
    printf("%25s: [%20lE, %20lE]\n", "double", DBL_MIN, DBL_MAX);
    printf("%25s: [%20LE, %20LE]\n", "long double", LDBL_MIN, LDBL_MAX);

    printf("\n");
    printf("======================= Ranges from calculations ======================\n");
    printf("%25s: [%20d, %20d]\n", "(signed) char", ~((unsigned char)~0 >> 1), (unsigned char)~0 >> 1);
    printf("%25s: [%20d, %20d]\n", "unsigned char", 0, (unsigned char)~0);
    printf("%25s: [%20d, %20d]\n", "(signed) short (int)", ~((unsigned short)~0 >> 1), (unsigned short)~0 >> 1);
    printf("%25s: [%20d, %20u]\n", "unsigned short (int)", 0, (unsigned short)~0);
    printf("%25s: [%20d, %20d]\n", "(signed) int", ~((unsigned int)~0 >> 1), (unsigned int)~0 >> 1);
    printf("%25s: [%20d, %20u]\n", "unsigned int", 0, (unsigned int)~0);
    printf("%25s: [%20ld, %20ld]\n", "(signed) long (int)", ~((unsigned long)~0 >> 1), (unsigned long)~0 >> 1);
    printf("%25s: [%20ld, %20lu]\n", "unsigned long (int)", 0L, (unsigned long)~0);
    printf("%25s: [%20lld, %20lld]\n", "(signed) long long (int)", ~((unsigned long long)~0 >> 1), (unsigned long long)~0 >> 1);
    printf("%25s: [%20lld, %20llu]\n", "unsigned long long (int)", 0LL, (unsigned long long)~0);

    return 0;
}
