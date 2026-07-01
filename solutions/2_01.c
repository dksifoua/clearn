// Exercise 2-1. Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned, by printing appropriate values
// from standard headers and by direct computation. Harder if you compute them:
// determine the ranges of the various floating-point types.

#include <float.h>
#include <limits.h>
#include <stdio.h>

int char_wordlength(void);
int short_wordlength(void);
int int_wordlength(void);
int long_wordlength(void);
int longlong_wordlength(void);
int float_wordlength(void);
int double_wordlength(void);
int longdouble_wordlength(void);

int main(void) {
  printf("======================== Ranges from standard headers\n");
  printf("%25s: [%20d, %20d]\n", "(signed) char", CHAR_MIN, CHAR_MAX);
  printf("%25s: [%20d, %20d]\n", "unsigned char", 0, UCHAR_MAX);
  printf("%25s: [%20d, %20d]\n", "(signed) short (int)", SHRT_MIN, SHRT_MAX);
  printf("%25s: [%20d, %20u]\n", "unsigned short (int)", 0, USHRT_MAX);
  printf("%25s: [%20d, %20d]\n", "(signed) int", INT_MIN, INT_MAX);
  printf("%25s: [%20d, %20u]\n", "unsigned int", 0, UINT_MAX);
  printf("%25s: [%20ld, %20ld]\n", "(signed) long (int)", LONG_MIN, LONG_MAX);
  printf("%25s: [%20ld, %20lu]\n", "unsigned long (int)", 0L, ULONG_MAX);
  printf("%25s: [%20lld, %20lld]\n", "(signed) long long (int)", LLONG_MIN,
         LLONG_MAX);
  printf("%25s: [%20lld, %20llu]\n", "unsigned long long (int)", 0LL,
         ULLONG_MAX);
  printf("%25s: [%20E, %20E]\n", "float", FLT_MIN, FLT_MAX);
  printf("%25s: [%20lE, %20lE]\n", "double", DBL_MIN, DBL_MAX);
  printf("%25s: [%20LE, %20LE]\n", "long double", LDBL_MIN, LDBL_MAX);

  int char_nbits = char_wordlength();
  char minchar = 1u << (char_nbits - 1), maxchar = ~minchar;
  unsigned char uminchar = 0u, umaxchar = ~uminchar;

  int short_nbits = short_wordlength();
  short minshort = 1u << (short_nbits - 1), maxshort = ~minshort;
  unsigned short uminshort = 0u, umaxshort = ~uminshort;

  int int_nbits = int_wordlength();
  int minint = 1u << (int_nbits - 1), maxint = ~minint;
  unsigned int uminint = 0u, umaxint = ~uminint;

  int long_nbits = long_wordlength();
  long minlong = 1uL << (long_nbits - 1), maxlong = ~minlong;
  unsigned long uminlong = 0uL, umaxlong = ~uminlong;

  int longlong_nbits = longlong_wordlength();
  long long minlonglong = 1uL << (longlong_nbits - 1), maxlonglong = ~minlonglong;
  unsigned long long uminlonglong = 0uL, umaxlonglong = ~uminlonglong;

  printf("\n");
  printf("======================= Ranges from calculations\n");
  printf("%25s (%02d bytes): [%20d, %20d]\n", "(signed) char", char_nbits / 8,
         minchar, maxchar);
  printf("%25s (%02d bytes): [%20u, %20u]\n", "unsigned char", char_nbits / 8,
         uminchar, umaxchar);
  printf("%25s (%02d bytes): [%20d, %20d]\n", "(signed) short", short_nbits / 8,
         minshort, maxshort);
  printf("%25s (%02d bytes): [%20u, %20u]\n", "unsigned short", short_nbits / 8,
         uminshort, umaxshort);
  printf("%25s (%02d bytes): [%20d, %20d]\n", "(signed) int", int_nbits / 8,
         minint, maxint);
  printf("%25s (%02d bytes): [%20u, %20u]\n", "unsigned int", int_nbits / 8,
         uminint, umaxint);
  printf("%25s (%02d bytes): [%20ld, %20ld]\n", "(signed) long", long_nbits / 8,
         minlong, maxlong);
  printf("%25s (%02d bytes): [%20lu, %20lu]\n", "unsigned long", long_nbits / 8,
         uminlong, umaxlong);
  printf("%25s (%02d bytes): [%20lld, %20lld]\n", "(signed) long long", longlong_nbits / 8,
         minlonglong, maxlonglong);
  printf("%25s (%02d bytes): [%20llu, %20llu]\n", "unsigned long long", longlong_nbits / 8,
         uminlonglong, umaxlonglong);

  return 0;
}

int char_wordlength(void) {
  int nbits = 1;
  unsigned char bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}

int short_wordlength(void) {
  int nbits = 1;
  unsigned short bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}

int int_wordlength(void) {
  int nbits = 1;
  unsigned int bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}

int long_wordlength(void) {
  int nbits = 1;
  unsigned long bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}

int longlong_wordlength(void) {
  int nbits = 1;
  unsigned long long bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}

int float_wordlength(void) {
  int nbits = 1;
  float bits = ~0;
  while ((bits >>= 1) > 0) {
    nbits += 1;
  }

  return nbits;
}
