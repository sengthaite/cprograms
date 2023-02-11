/*
* To handle stack
*/

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
        return val[sp];
    printf("Error: pop value from empty stack!");
    return 0.0;
}