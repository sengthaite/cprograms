/* Character Input and Output */

// getchar()
// putchar()

// copy input to output
#include <stdio.h>

int main(void) {
    int c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}
