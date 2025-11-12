#include <stdio.h>
#define SYSTEM MACOSX

#ifdef SYSTEM
    #if SYSTEM == MACOSX
        #define MESSAGE "It is Mac."
    #elif SYSTEM == LINUX
        #define MESSAGE "It is Linux."
    #else
        #define MESSAGE "Unknown."
    #endif
#endif

#ifndef JOKE
    #define JOKE(s) printf("%s\n", s);
#endif

#ifndef HELLOWORLD
    #define HEADER "macro_conditional.h"
#endif

#include HEADER

int main(void)
{
    printf("%s\n", MESSAGE);
    JOKE("It is a joke.")
    printf("%d\n", SOME_MACRO);
    return 0;
}