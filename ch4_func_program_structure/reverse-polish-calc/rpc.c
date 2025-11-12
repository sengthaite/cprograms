#include <stdio.h>
#include <stdlib.h> // atof
#include <string.h> // strcmp
#include <math.h> // fmod, sin, exp, pow
#include "cal.h"

void handle_variable(char []);

int main(void)
{
    char c;
    char s[MAXVAL];
    double tmp;

    while ((c = getop(s)) != EOF)
    {
        switch (c)
        {
        case VARIABLE:
            handle_variable(s);
            break;
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            tmp = pop();
            push(pop() - tmp);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            tmp = pop();
            if (tmp == 0)
                printf("Error: divide by 0\n");
            else
                push(pop() / tmp);
            break;
        case '%':
            tmp = pop();
            if (tmp == 0)
                printf("Error: divide by 0\n");
            else
                push(fmod(pop(), tmp));
            break;
        default:
            break;
        }
    }

    printf("Final result: %f\n", pop());

    return 0;
}

void handle_variable(char s[])
{
    if (!strcmp(s, "sin"))
        push(sin(pop()));
    if (!strcmp(s, "exp"))
        push(exp(pop()));
    if (!strcmp(s, "pow")) {
        double tmp = pop();
        push(pow(pop(), tmp));
    }
    if (!strcmp(s, "top"))
        head();
    if (!strcmp(s, "dup"))
        duplicate();
    if (!strcmp(s, "swap"))
        swap();
}