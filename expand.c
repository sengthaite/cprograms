#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

// case a-z or A-Z
// case a-z0-9
// case a-b-c
// -a-z

char *expand(char *str);

int main()
{
    printf("%s\n", expand("a-z"));
    printf("%s\n", expand("-a-z"));
    printf("%s\n", expand("a-z-"));
    printf("%s\n", expand("-a-z-"));
    printf("%s\n", expand("a-z0-9"));
    printf("%s\n", expand("0-9"));
    printf("%s\n", expand("A-Z"));
    printf("%s\n", expand("a-b-c-"));
    return 0;
}

char *expand(char *expr)
{
    int c, i, j;
    i = j = 0;
    char *result = malloc(MAXSIZE + 1);
    while((c = expr[i++]) != '\0')
    {
        if (expr[i] == '-' && expr[i+1] >= c)
        {
            i++;
            while(c < expr[i])
                result[j++] = c++;
        }
        else
            result[j++] = c;
        result[j] = '\0';
    }  
    return result;
}