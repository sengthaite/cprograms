#include <stdio.h>

int main(void)
{
    void *type;
    int someval = 10;
    type = &someval;
    printf("%d\n", *(int *)type);
    printf("address of someval %p\n", &someval);
    printf("address of (int *)type %p\n", (int *)type);
    return 0;
}