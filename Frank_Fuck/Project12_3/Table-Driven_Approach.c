#include<stdio.h>
#include <stdbool.h>

bool isLeap(int year);
int days(int month, int year);

int main(void)
{
    int month, year;
    printf("请输入年份和月份:");
    scanf_s("%d %d", &year,&month);

    int result = days(month, year);
    printf("%d年%d月有%d天", year, month, result);
    return 0;
}

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) /*闰年算法*/
        return true;
    else
        return false;
}

int days(int month, int year)
{
    int days[12] = { 31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
    return days[month - 1];
}