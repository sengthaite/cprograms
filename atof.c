#include <ctype.h>
#include <stdio.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    int exp = 0, cur, mul = 1;
    char exp_sign;
    if (s[i++] == 'e')
        while((cur = s[i]) != '\0')
        {
            i++;
            if (cur == '-') {
                exp_sign = '-';
                continue;
            }
            exp = exp * mul + (cur - '0');
            mul *= 10;
        }
    while (exp-- > 0)
        power = exp_sign == '-' ? power * 10 : power / 10;

    
    return sign * val / power;
}

int main(void)
{
    printf("%s to double = %f\n", "123.45e-2", atof("123.45e-2"));
    return 0;
}