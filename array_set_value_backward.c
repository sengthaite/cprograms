/*
* Value to array backward
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char my_array[3];
    my_array[2] = '\0';
    my_array[1] = 't';
    my_array[0] = 'a';
    char *another_array = malloc(3);
    another_array[2] = '\0';
    another_array[1] = 'i';
    another_array[0] = 'm';
    printf("%s\n", my_array);
    printf("%s\n", another_array);
    return 0;
}