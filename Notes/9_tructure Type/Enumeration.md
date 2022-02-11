# Enumeration

> 枚举: https://www.runoob.com/cprogramming/c-enum.htmlhthttps://www.runoob.com/cprogramming/c-enum.html

## C 枚举

枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读。

枚举语法定义格式为：

```c
enum　枚举名　{枚举元素1,枚举元素2,……};
```

接下来我们举个例子，比如：一星期有 7 天，如果不用枚举，我们需要使用 #define 来为每个整数定义一个别名：

```C
#define MON  1
#define TUE  2
#define WED  3
#define THU  4
#define FRI  5
#define SAT  6
#define SUN  7
```

这个看起来代码量就比较多，接下来我们看看使用枚举的方式：

```c
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
```

这样看起来是不是更简洁了。

**注意：**第一个枚举成员的默认值为整型的 0，==后续枚举成员的值在前一个成员上加 1==。

我们在这个实例中把第一个枚举成员的值定义为 1，第二个就为 2，以此类推。

---

我们也可以在定义枚举类型时改变枚举元素的值

```C
enum season {spring, summer=3, autumn, winter};
```

==没有指定值的枚举元素，其值为前一元素加 1。==

也就说` spring` 的值为 0，`summer` 的值为 3，`autumn`的值为 4，`winter `的值为 5。

我们可以通过以下三种方式来定义枚举变量

**1、先定义枚举类型，再定义枚举变量**

```c
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day;
```

**2、定义枚举类型的同时定义枚举变量**

```c
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

**3、省略枚举名称，直接定义枚举变量**

```
enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

实例

```c
#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
int main(void)
{
    enum DAY day;
    day = WED;
    printf("%d",day);
    return 0;
}
```

以上实例输出结果为：

```
3
```

==在C 语言中，枚举类型是被当做 int 或者 unsigned int 类型来处理的==，所以按照 C 语言规范是没有办法遍历枚举类型的。

不过在一些特殊的情况下，枚举类型必须连续是可以实现有条件的遍历。

以下实例使用 for 来遍历枚举的元素：

```c
#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
int main()
{
    // 遍历枚举元素
    for (day = MON; day <= SUN; day++) {
        printf("枚举元素：%d \n", day);
    }
}
```

以上实例输出结果为：

```
枚举元素：1 
枚举元素：2 
枚举元素：3 
枚举元素：4 
枚举元素：5 
枚举元素：6 
枚举元素：7
```

以下枚举类型不连续，这种枚举无法遍历。

```c
enum
{
    ENUM_0,
    ENUM_10 = 10,
    ENUM_11
};
```

## 枚举在 switch 中的使用：

> **swith语句**
>
> ```c
> switch(表达式)
> {
>     case 常量表达式1:语句1;
>     case 常量表达式2:语句2;
>     ...
>     default:语句n+1;
> }
> ```
>
> 意思是先计算表达式的值，再逐个和 case 后的常量表达式比较，若不等则继续往下比较，若一直不等，则执行 default 后的语句；
>
> 若等于某一个常量表达式，则从这个表达式后的语句开始执行，并执行后面所有 case 后的语句。
>
> 与 if 语句的不同：if 语句中若判断为真则只执行这个判断后的语句，执行完就跳出 if 语句，不会执行其他 if 语句；==而 switch 语句不会在执行判断为真后的语句之后跳出循环，而是继续执行后面所有 case 语句==。
>
> 在每个 case 语句之后增加 break 语句，使每一次执行之后均可跳出 switch 语句，从而避免输出不应有的结果。

实例

```c
#include <stdio.h>

int main(void)
{
 
    enum color { red=1, green, blue };
 
    enum  color favorite_color;
 
    /* 用户输入数字来选择颜色 */
    printf("请输入你喜欢的颜色代码: (1. red, 2. green, 3. blue): ");
    scanf("%u", &favorite_color);
 
    /* 输出结果 */
    switch (favorite_color)
    {
    case red:
        printf("你喜欢的颜色是红色");
        break;
    case green:
        printf("你喜欢的颜色是绿色");
        break;
    case blue:
        printf("你喜欢的颜色是蓝色");
        break;
    default:
        printf("你没有选择你喜欢的颜色");
    }
 
    return 0;
}
```

以上实例输出结果为：

```
请输入你喜欢的颜色: (1. red, 2. green, 3. blue): 1
你喜欢的颜色是红色
```

## 自动计数的枚举

```C
enum{RED,YELLOW,GREEN,numberOfColor};
```

`numerOfColor`的值为3,可以代表前面有三个枚举成员.

这样需要遍历所有枚举量或者需要建立一个用枚举量作下标的数组的时候就很方便了.

```C
#include<stdio.h>

enum COLOR { RED, YELLOW, GREEN, NumCOLORS };

int main(int argc, char const* argv[])
{
	int color = -1;
	char* ColorNames[NumCOLORS] = 
	{
		"red","yellow","green",
	};
	char* colorName = NULL;

	printf("请输入你喜欢的颜色代码:");
	scanf_s("%d", &color);
	if (color >= 0 && color < NumCOLORS) 
	{
		colorName = ColorNames[color];
	}
	else 
	{
		colorName = "unknown";
	}
	printf("你喜欢的颜色是%s\n",colorName);

	return 0;
}
```

## 将整数转换为枚举

实例

```c
#include <stdio.h>
 
int main(void)
{
    enum day
    {
        Saturday,
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday
    } workday;
 
    int a = 1;
    enum day weekend;
    weekend = ( enum day ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d",weekend);
    return 0;
}
```

以上实例输出结果为：

```
weekend:1
```