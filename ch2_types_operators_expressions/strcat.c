/* 
* A simple program to append an array to the end of another array.
*/

#include <stdio.h>

// Append c to s; s size must be big enough
void strcat(char s[], char c[])
{
    int i, j = 0;
    // find index of the array s
    while(s[i] != '\0')
        i++;
    while((s[i++] = c[j++]) != '\0');
}

int main()
{
    char first_sentence[1000] = "This is the first sentence. ";
    char second_sentence[] = "Luckily, this is appened.";
    strcat(first_sentence, second_sentence);
    printf("Final array after concat: %s\n", first_sentence);
}