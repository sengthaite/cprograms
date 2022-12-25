#include <stdio.h>
#define MAXLINE 1000
/*
List of escape char: 
====================
\a: alert 
\b: backspace
\f: formfeed
\n: newline
\r: carriage return
\t: horizontal tab
\v: vertical tab
\\: backslash
\?: question mark
\': single quote
\": double quote
\000: octal number
\xhh: hexadecimal number
*/

void escape(char *s, char *t);

int main()
{
    char s[MAXLINE], t[MAXLINE];
    char c;
    int i = 0;
    while((c = getchar()) != EOF)
    {
        t[i] = c;
        ++i;
    }
    t[i] = '\0';
    escape(s, t);
    printf("Escaped text: %s\n", s);
    return 0;
}

void escape(char *s, char *t)
{
    int i = 0, j = 0;
    while(t[i] != '\0')
    {
        switch(t[i])
        {
            case '\n':
                s[j] = '\\';
                ++j;
                s[j] = 'n';
                break;
            case '\t':
                s[j] = '\\';
                ++j;
                s[j] = 't';
                break;
            default:
                s[j] = t[i];
                break;
        }

        ++i;
        ++j;
    }
    s[j] = '\0';
}