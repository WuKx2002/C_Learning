#include<stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main_1(void)
{
    struct date today, tomorrow;
    printf("Enter todays's date(mm dd yyyy):");
    scanf_s("%i %i %i", &today.month, &today.day, &today.year);

    if (today.day != numberOfDays(today))
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12)
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }

    printf("Tomorrow's date is %i-%i-%i.\n",
        tomorrow.year, tomorrow.month, tomorrow.day);
    return 0;
}

bool isLeap(struct date d)
{
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) /*»ÚƒÍÀ„∑®*/
        return true;
    else
        return false;
}

int numberOfDays(struct date d)
{
    int days[12] = { 31,isLeap(d) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
    return days[d.month - 1];
}