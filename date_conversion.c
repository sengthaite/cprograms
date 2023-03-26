/// Date conversion program

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
    printf("day of year: %d\n", day_of_year(2023, 2, 28));
    int pmonth, pday;
    month_day(2023, day_of_year(2023, 2, 28), &pmonth, &pday);
    printf("pmonth %d\n", pmonth);
    printf("pday %d\n", pday);
    return 0;
}

static char daytab[2][13] = {
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

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if (year <= 0 || yearday <= 0) {
        printf("Invalid year or yearday\n");
        return 1;
    }
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}