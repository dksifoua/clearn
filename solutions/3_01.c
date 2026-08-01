// Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at
// the price of more tests outside.) Write a version with only one test inside the loop and measure
// the difference in run-time. 

#include <stdio.h>

const int binsearch(const int x, const int v[], const unsigned n);

int main(void) {
    int n = 100;
    int array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = i;
    }
    printf("binsearch(%d, v[0..%d], %d) = %d\n", -1, n, n, binsearch(-1, array, n));
    printf("binsearch(%d, v[0..%d], %d) = %d\n", 25, n, n, binsearch(25, array, n));
    printf("binsearch(%d, v[0..%d], %d) = %d\n", 50, n, n, binsearch(50, array, n));
    printf("binsearch(%d, v[0..%d], %d) = %d\n", 75, n, n, binsearch(75, array, n));
    printf("binsearch(%d, v[0..%d], %d) = %d\n", 101, n, n, binsearch(101, array, n));
    return 1;
}

const int binsearch(const int x, const int v[], const unsigned n) {    
    int low = 0, high = n - 1, middle = 0;
    while (low < high) {
        middle = low + (high - low) / 2;
        if (x <= v[middle]) {
            high = middle;
        } else {
            low = middle + 1;
        }
    }

    return x == v[high] ? high : -1;
}
