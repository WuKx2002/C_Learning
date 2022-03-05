# Dice

## 生成随机数

C 库函数` int rand(void)` 返回一个范围在 `0 `到 `RAND_MAX`之间的伪随机数。

`RAND_MAX `是一个常量，它的默认值在不同的实现中会有所不同，但是值至少是 `32767`。

**声明**
下面是 rand() 函数的声明。
```c
int rand(void)
```

**参数**
`void`

**返回值**
该函数返回一个范围在` 0 `到 `RAND_MAX`之间的整数值。

**实例**
下面的实例演示了` rand() `函数的用法。
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
   int i, n;
   time_t t;
   
   n = 5;
   
   /* 初始化随机数发生器 */
   srand((unsigned) time(&t));
 
   /* 输出 0 到 49 之间的 5 个随机数 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }
   
  return 0;
}
```
让我们编译并运行上面的程序，这将产生以下结果：
```
38
45
29
29
47
```

> 自动重置种子
>
> 如果C实现允许访问一些可变的量（如，时钟系统），可以用这些值（可能被截断）初始化种子值。
>
> 例如ANSI C 中**`time()`函数**返回系统时间，是一个随时间而变化的可运算值。返回值的类型名为`time_t`。
> 我们可以强制类型转换：
>
> ```c
> #include <time.h> //提供time()的ANSI原型
> srand1((unsigned int) time(0));
> ```
> **`srand()`函数 **
>
> C 库函数` void srand(unsigned int seed)` 播种由函数 `rand() `使用的随机数发生器。
>
> 声明`void srand(unsigned int seed)`
>
> 参数`seed`是一个整型值，用于伪随机数生成算法播种。

❗ 如果要使用`rand()`和`srand()`函数，要在文件中包含`stdlib.h`头文件。

## 掷骰子

假设骰子有`side`个面，那么随机数的范围就是`1~side`，我们可以通过求模运算获得一个这个范围内的随机数。

```c
rand() % side + 1
```

下面的代码块实现了这个过程：

```c
#include <stdlib.h>

int rollem(int sides)
{
	int roll;

	roll = rand() % sides + 1;
	
	return roll;
}
```
下面设计完整的程序

```c
//r_drivel.c
#include <stdio.h>
#include <stdlib.h> //为库函数srand()和rand()提供原型
#include <time.h>	//为库函数time()提供原型
#include "dicroll.h"//为roll_n_dice()提供原型，为roll_count提供声明

int roll_count = 0; //静态外部链接

static int rollem(int sides) //生成每个骰子随机数，静态内部链接，函数为该文件私有。
{
	int roll;

	roll = rand() % sides + 1;
	roll_count++;

	return roll;
}

int roll_n_dice(int dice, int sides)//求各骰子随机数之和。
{
	int total = 0;
	int ret = 0;//返回值单一出口。

	if (sides < 2)
	{
		fputs("Need at least 2 sides.\n", stdout);
		ret = -2;
	}
	if (dice < 1)
	{
		fputs("Need at least 1 die.\n", stdout);
		ret = -1;
	}
	for (int i = 0; i < dice; i++)
	{
		total += rollem(sides);
		ret = total;
	}

	return ret;
}
```

```c
//dicroll.h
_n_dice(int dice, int sides);

extern int roll_count;//静态外部链接变量
```

```c
//manydice.c
#include <stdio.h>
#include <stdlib.h> //为库函数srand()和rand()提供原型
#include <time.h>	//为库函数time()提供原型
#include "dicroll.h"//为roll_n_dice()提供原型，为roll_count提供声明

int main(void)
{
	int sides;
	int status;
	int dice;

	srand((unsigned int)time(0));//随机种子
	fputs("Enter the number of sides per die, 0 to stop.\n", stdout);
	while (scanf_s("%d", &sides) == 1 && sides > 0)//输入验证
	{
		fputs("How many dice ?\n", stdout);
		if ((status = scanf_s("%d", &dice) != 1))
		{
			if (status == EOF)
				break;
			else
			{
				fputs("Please enter an integer.\n", stdout);
				fputs("Let's start again.\n", stdout);
				while (getchar() != '\n')
					continue;//清除缓冲区的错误输入
				fputs("How many dice ? Enter 0 to stop.\n", stdout);
				continue;//重新回到循环起点读取输入
			}
		}
		int roll = roll_n_dice(dice, sides);
		printf("You have rolled a %d using %d %d-sided dice.\n", 
			roll, dice, sides);
		fputs("How many dice ? Enter 0 to stop.\n", stdout);
	}
	printf("The rollem() function was called %d times.\n", roll_count);
	fputs("Good Forturn to You ?\n", stdout);
	return 0;
}
```



