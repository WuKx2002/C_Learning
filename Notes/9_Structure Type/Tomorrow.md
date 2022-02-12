# Tomorrow

**目标:输入日期后计算出下一天的日期**

之前,在*Table-Driven_Approach*中应用表驱动法写过求出某年某月天数的代码.

其中两个重要的函数`isLeap`和`numberOfDays`:

```c
bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) /*闰年算法*/
         return true;
	else
         return false;
}

int numberOfDays(int month,int year)
{
	int days[12] = {31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    return days[month-1];
}
```

我们声明一个包含月,日,年的结构体:

```c
struct date
{
  int month;
  int day;
  int year;  
};
```

然后定义`isLeap`和`numberOfDays`函数:

```c
bool isLeap(struct date d)
{
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) /*闰年算法*/
         return true;
	else
         return false;
}
int numberOfDays(struct date d)
{
    int days[12] = {31,isLeap(d) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    return days[d.month-1];
}
```

`main`函数:

```c
int main(void)
{
    struct date today,tomorrow;
    printf("Enter todays's date(mm dd yyyy):");
    scanf_s("%i %i %i",&today.month,&today.day,&today.year);
    
    if(today.day != numberOfDays(today))
    {
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if(today.month == 12)
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
          tomorrow.year,tomorrow.month,tomorrow.day);
    return 0;
}
```

**完整代码:**

```C
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

int main(void)
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
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) /*闰年算法*/
        return true;
    else
        return false;
}

int numberOfDays(struct date d)
{
    int days[12] = { 31,isLeap(d) ? 29 : 28,31,30,31,30,31,31,30,31,30,31 };
    return days[d.month - 1];
}
```
