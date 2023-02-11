/*
* To handle stack
*/

#include <stdio.h>

#define MAXSTACK 1000

double val[1000];
int sp = 0;

void push(double value)
{
    val[sp++] = value;
}

double pop()
{
    if (sp > 0)
        return val[--sp];
    printf("Error: pop value from empty stack!\n");
    return 0.0;
}

void head()
{
    if (sp > 0)
        printf("Top element in stack : %f\n", val[--sp]);
    else
        printf("Stack empty\n");
}

void duplicate()
{
    double tmp = pop();
    push(tmp);
    push(tmp);
}

void swap()
{
    double last_tmp = pop();
    double tmp = pop();
    push(last_tmp);
    push(tmp);
}

void clear()
{
    sp = 0;
}