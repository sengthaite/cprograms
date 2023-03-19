#include <stdio.h>
#include <string.h>

#define MAXLINE 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINE];

int readlines(char *lineptr[], int nlines);
int readlines2(char *lineptr[], char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void) 
{
    int nlines;
    char linestore[ALLOCSIZE];

    if ((nlines = readlines2(lineptr, linestore, MAXLINE)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000
int _getline(char *, int);
char *alloc(int);

int readlines2(char *lineptr[], char *linestore, int maxlines)
{
    int len, nlines;
    char *p = linestore;
    char line[MAXLEN];
    char *linestop = linestore + ALLOCSIZE;

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) {
        if ((nlines >= maxlines) || (p + len > linestop))
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = _getline(line, MAXLEN)) > 0) {
        if ((nlines >= maxlines) || ((p = alloc(len)) == NULL))
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

int _getline(char *s, int n)
{
    int c;
    char *tmp = s;
    while(n-- > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - tmp;
}

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}