/*
* A simple program to sum two number without worrying about the length of the number
*/

#include <stdio.h>
#include <stdlib.h>

int max(int n1, int n2);
char *sum(char *n1, char *n2);

int main(int argc, char **argv)
{
    int c;
    if (argc != 3) 
        return 1;
    char *first_number = argv[1];
    char *second_number = argv[2];
    char *result = sum(first_number, second_number);
    printf("%s + %s = %s\n", first_number, second_number, result);
    return 0;
}

int max(int n1, int n2)
{
    return n1 > n2 ? n1 : n2;
}

int min(int n1, int n2)
{
    return n1 > n2 ? n2 : n1;
}

char *sum(char *n1, char *n2)
{
    int cn1, cn2;
    cn1 = cn2 = 0;
    char *first_number, *second_number, *tmp_number;
    while(n1[cn1] != '\0')
        ++cn1;
    while(n2[cn2] != '\0')
        ++cn2;

    int maxSize = max(cn1, cn2) - 1;
    int minSize = min(cn1, cn2) - 1;
    second_number = malloc(maxSize + 1);
    // make the first_number to be the longest number
    first_number = cn1 > cn2 ? n1 : n2;
    tmp_number = cn1 > cn2 ? n2 : n1;
    while(maxSize >= 0)
    {
        if (minSize >= 0)
        {
            second_number[maxSize] = tmp_number[minSize];
            --minSize;
        }
        else {
            second_number[maxSize] = '0';
        }
        --maxSize;
    }

    // check if need additional byte to store the char
    int isNeedAdditionalByte = first_number[0] + second_number[0] - (2 * '0') >= 10 ? 1 : 0;
    int j, tmp_add;
    tmp_add = 0;
    j = max(cn1, cn2) + (isNeedAdditionalByte ? 1 : 0);
    char *result;
    result = malloc(j);
    free(second_number);
    free(result);
    while(j > 0)
    {
        int added = first_number[j-1] + second_number[j-1] - (2 * '0') + tmp_add;
        char trailing = added % 10 + '0';
        tmp_add = added > 9 ? 1 : 0;
        result[j-1] = trailing;
        --j;
    }
    return result;
}