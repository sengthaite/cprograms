#include <stdio.h>

int main(void)
{
    char third_text[10] = "third text";
    char *third_textp = third_text;

    printf("address of &third_textp is %p\n", &third_textp);
    printf("address of third_textp + sizeof(third_text) is %p\n", third_textp + sizeof(third_text));
    printf("address of &third_text is %p\n", &third_text);
    printf("address of &third_text + 1 is %p\n", &third_text + 1);
    printf("address of &third_text[10] is %p\n", &third_text[10]);
    int i;
    for(i = 0; *third_textp != '\0'; third_textp++, i++) {
        printf("address of char %c at index %d is %p\n", *third_textp, i, &(* third_textp));
    }
    return 0;
}