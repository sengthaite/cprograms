#include <stdio.h>

int strindex(char s[], char t[]);
int strindexp(char *, char *);

int main(void)
{
    printf("%d\n", strindex("what is your name?", "ia"));
    return 0;
}

int strindex(char s[], char t[])
{
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}