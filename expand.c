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

// char *expand(char *expr)
// {
//     int i = 0, j = 0;
//     char *result = malloc(MAXSIZE);
//     char start, sep, end;
//     start = sep = end = 0;
//     while(expr[i] != '\0')
//     {
//         switch (expr[i])
//         {
//             case 'a':
//             case 'A':
//             case '0':
//                 if (sep)
//                 {
//                     result[j] = start;
//                     ++j;
//                     result[j] = sep;
//                     ++j;
//                     result[j] = expr[i];
//                     ++j;
//                     sep = 0;
//                     start = 0;
//                     end = 0;
//                 } else {
//                     start = expr[i];
//                 }
//                 break;
//             case 'z':
//             case 'Z':
//             case '9':
//                 if (sep)
//                 {
//                     for (int k = 0; start + k <= expr[i]; k++)
//                     {
//                         result[j] = start + k;
//                         ++j;
//                     }
//                     start = 0;
//                     end = 0;
//                     sep = 0;
//                 } else {
//                     start = expr[i];
//                 }
//                 break;
//             case '-':
//                 if (!start && !end)
//                 {
//                     result[j] = '-';
//                     ++j;
//                 }
//                 else 
//                     sep = '-';
//                 break;
//             default:
//                 return NULL;
//         }
//         ++i;
//     }
//     result[j] = '\0';
//     return result;
// }