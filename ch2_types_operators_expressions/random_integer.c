/*
* Pseudo-random number generator
*/

#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main()
{
    srand(2);
    for (int i = 0; i < 100; ++i)
        printf("Random number %d\n", rand());
    return 0;
}

int rand(void)
{
    next = next * 1103515245 + 12345; // LCGs 1103515245
    return (unsigned int)(next / 65536) % 32768; // untouchable number 65536
}

void srand(unsigned int seed)
{
    next = seed;
}