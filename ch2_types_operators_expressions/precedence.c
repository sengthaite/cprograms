/* precedence.c
 * e.g. c = getchar() != EOF the same as c = (getchar() != EOF) */

#include <stdio.h>

int main() {
    int c;
    c = 10 != 0;
    printf("%d\n", c);
    return 0;
}
