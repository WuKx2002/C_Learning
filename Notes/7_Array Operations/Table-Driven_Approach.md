# Table-Driven_Approach

>**表驱动法(Table-Driven_Approach)**就是一种编程模式(scheme)——从表里面查找信息而不使用逻辑语句(if 和case)。
>
>事实上，凡是能通过逻辑语句来选择的事物，都可以通过查表来选择。对简单的情况而言，使用逻辑语句更为容易和直白。但随着逻辑链的越来越复杂，查表法也就愈发显得更具吸引力。

**案例:输入年份和月份,输出该月份的天数.**

已知每个月份的天数

| 1月  | 2月    | 3月  | 4月  | 5月  | 6月  | 7月  | 8月  | 9月  | 10月 | 11月 | 12月 |
| ---- | ------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 31   | 28或29 | 31   | 30   | 31   | 30   | 31   | 31   | 30   | 31   | 30   | 31   |

- 定义一个写好每个月天数的数组

  `int days[12] = {31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};`

  由于二月的天数收到年份的影响,平年2月有28天,闰年2月有29天.

  所以定义一个`isLeap(int year);`函数来判断用户输入的年份`year`对应的2月的天数.

  `isLeap(year) ? 29 : 28`是**三元运算符**,可以用来替代if或者case语句.

  > 三元运算符
  >
  > 一般形式:`Exp1 ? Exp2 : Exp3;`
  >
  > 其中，`Exp1`、`Exp2 `和` Exp3 `是表达式.
  >
  > 如果 `Exp1 `为真，则计算`Exp2 `的值，结果即为整个表达式的值。如果` Exp1 `为假，则计算 `Exp3 `的值，结果即为整个表达式的值.

- 定义一个返回**bool类型**值的函数`isLeap`判断2月的天数

  > **布尔类型**（bool）
  >
  > 布尔类型只有两个值，false 和 true。
  >
  > 通常用来判断条件是否成立。
  >
  > C语言语法规定，如果变量值为 0 就是 false，否则为 true,布尔变量只有这两个值。	
  >
  > C89 没有定义布尔类型.
  >
  > C99 提供了一个头文件` <stdbool.h> `定义了 bool 代表 _Bool，true 代表 1，false 代表 0。

函数代码块

```C
#include <stdbool.h>

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)/*闰年算法*/
         return true;
	else
         return false;
}
```

- 结合上述,定义一个判断每个月有多少天的函数`days`

函数代码块

```C
int days(int month,int year)
{
	int days[12] = {31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    return days[month-1];
}
```

**完整代码**

```C
#include<stdio.h>
#include <stdbool.h>

bool isLeap(int year);
int days(int month,int year);

int main(void)
{
    int month,year;
    printf("请输入年份和月份:");
	scanf_s("%d %d",&year,&month);
    int result = days(month,year);
    printf("%d年%d月有%d天",year,month,result);
	return 0;
}

bool isLeap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) /*闰年算法*/
         return true;
	else
         return false;
}

int days(int month,int year)
{
	int days[12] = {31,isLeap(year) ? 29 : 28,31,30,31,30,31,31,30,31,30,31};
    return days[month-1];
}
```

