#include <stdio.h>

char *lowercase(char *s);

int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    printf("lowercase of %s\n", lower(argv[1]));
    return 0;
}

char *lowercase(char *s)
{
    for (int i = 0; s[i] != '\0'; ++i)
        s[i] = s[i] + (s[i] >= 'A' && s[i] <= 'Z' ? 'a' - 'A' : 0);
    return s;
}