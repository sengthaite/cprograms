/*
* Remove all specified characters from given string
*/

#include <stdio.h>

void squeeze(char s[], char c[]);

int main()
{
    char full_sentence[] = "This is the full sentence.";
    char string_to_remove[] = "s";
    squeeze(full_sentence, string_to_remove);
    printf("After remove %s from the full sentence: %s\n", string_to_remove, full_sentence);
    return  0;
}

void squeeze(char s[], char c[])
{
    int i, j, k;
    for(i = j = k = 0; s[i] != '\0'; i++)
    {
        int is_found = 0;
        while(c[j] != '\0')
        {
           is_found = c[j] == s[i];
           if (is_found)
           {
                break;
           }
            ++j;
        }
        if (!is_found)
        {
            s[k] = s[i];
            k++;
        }
        j = 0;
    }
    s[k] = '\0';
}