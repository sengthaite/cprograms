#include <stdio.h>

int main()
{
    int c;
    int wc = 0;
    while((c = getchar()) != EOF) 
    {
        wc++;
    }
    printf("Char counts: %d\n", wc);
    return 0;
}