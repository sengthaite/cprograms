#include <stdio.h>

char last_char(char *);

int main(void)
{
    char text[4] = "when";
    printf("last char of text is %c\n", ((char *)(&text +1)-1)[0]);
    printf("add of text is %p\n", &text);
    printf("add of text[0] is %p\n", &text[0]);
    printf("add of text[4] is %p\n", &text[4]);
    printf("last char of text is %c\n", last_char(text));
    return 0;
}

char last_char(char *s) {
    while(*s != '\0') s++; return *(--s);
} 