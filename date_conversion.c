/// Date conversion program

#include <stdio.h>

int day_of_year(int year, int month, int day);
int day_of_yearp(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
void month_dayp(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    printf("day of year: %d\n", day_of_year(2023, 2, 20));
    int pmonth, pday;
    month_day(2023, day_of_year(2023, 2, 20), &pmonth, &pday);
    printf("pmonth %d\n", pmonth);
    printf("pday %d\n", pday);
    return 0;
}

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    if (year <= 0 || month <= 0 || day <= 0) {
        printf("Invalid year or month or day\n");
        return 1;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

int day_of_yearp(int year, int month, int day)
{
    if (year <= 0 || month <= 0 || day <= 0) {
        printf("Invalid year or month or day\n");
        return 1;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int *p;
    p = &daytab[leap][1];
    for (i = 1; i < month; i++) {
        day += *p++;
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year <= 0 || yearday <= 0) {
        printf("Invalid year or yearday\n");
        return;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

void month_dayp(int year, int yearday, int *pmonth, int *pday)
{
    if (year <= 0 || yearday <= 0) {
        printf("Invalid year or yearday\n");
        return;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    int *p;
    p = &daytab[leap][1];
    for (i = 1; yearday > *p++; i++)
        yearday -= *p;
    *pmonth = i;
    *pday = yearday;
}