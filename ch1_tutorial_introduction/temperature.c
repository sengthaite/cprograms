/* A simple program to print a table of temperature conversion fahrenheit to celsius */

#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 20

int main() {
    int fahr;
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3d %6.1f\n", fahr, 5.0 * (fahr - 32) / 9.0);
    }
    return 0;
}
