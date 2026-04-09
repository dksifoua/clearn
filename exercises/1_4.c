#include <stdio.h>

#define LOWER 0
#define STEP 20
#define UPPER 300

void celsius2fahrenriet() {
    float celsius = LOWER, fahrenheit;
    printf("Celsiust\tFahrenheit\n");
    while (celsius <= UPPER) {
      fahrenheit = celsius * (9.f /5) + 32;
      printf("%3.0f\t\t%5.1f\n", celsius, fahrenheit);
  
      celsius += STEP;
    }
}

int main() {
    celsius2fahrenriet();
    return 0;
}
