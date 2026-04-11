#include <stdio.h>

#define LOWER 0
#define STEP 20
#define UPPER 300

int main() {
    float fahrenheit = LOWER, celsius;
    printf("Fahrenheit\tCelsius\n");
    while (fahrenheit <= UPPER) {
      celsius = (5.0f / 9) * (fahrenheit - 32);
      printf("%3.0f\t\t%5.1f\n", fahrenheit, celsius);
  
      fahrenheit += STEP;
    }
    return 0;
}
