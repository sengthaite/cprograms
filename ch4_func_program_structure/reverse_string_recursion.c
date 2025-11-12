#include <stdio.h>

void reverse(char *s, int place);

int main(void)
{
    char test_string[] = "orange";
    reverse(test_string, 2);
    printf("after reversed: %s\n", test_string);
    return 0;
}

void reverse(char *s, int place)
{
    if (place < 2)
        return;
    static int i = 0;
    char tmp = s[i];
    s[i] = s[place - i - 1];
    s[place - i - 1] = tmp;
    i++;

    if (place / 2 > i) {
        reverse(s, place);
    }
}
