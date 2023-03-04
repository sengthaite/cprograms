/*
print first character
*/

#include <stdio.h>

int main(void)
{
    char *text = "some text";
    char *textp; textp = &text[0];
    char *cpytext = text;
    char *addrtext; addrtext = &(text[1]);

    printf("first char of \"%s\" is \"%c\"\n", text, text[0]);
    printf("first char of \"%s\" is \"%c\"\n", text, *text);
    printf("first char of \"%s\" is \"%c\"\n", text, *textp);

    printf("address of &text: %p\n", &text);
    printf("address of &cpytext: %p\n", &cpytext);
    printf("address of &(*text): %p\n", &(*text));
    printf("address of &(*cpytext): %p\n", &(*cpytext));
    printf("addresss of &text[0]: %p\n", &text[0]);
    printf("addess of &textp: %p\n", &textp);
    printf("addess of &(*textp): %p\n", &(*textp));

    printf("addrtext: %s\n", addrtext);
    
    // char another_text[] = "another text";
    // printf("first char of \"%s\" is \"%c\"\n", another_text, another_text[0]);
    // printf("first char of \"%s\" is \"%c\"\n", another_text, *another_text);

    // char size_text[9] = "size text";

    return 0;
}