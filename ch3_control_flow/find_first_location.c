/*
* a program to return the first location in the string s1 where any character from the string s2 occur, or -1 if no character found.
*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char first_string[] = "In my mind";
    char second_string[] = "d";
    int index = any(first_string, second_string);
    if (index != -1)
        printf("Found location of the first char which is in second string %d.\n", index);
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    while(s1[i] != '\0')
    {
        while(s2[j] != '\0')
        {
            if (s1[i] == s2[j])
                return i;
            ++j;
        }
        j = 0;
        ++i;
    }
    return -1;
}