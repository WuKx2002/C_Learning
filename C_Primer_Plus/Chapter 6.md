# Chapter 6
## 1
```c
#include <stdio.h>

int main(void)
{
	char array[26];
	char cnt = 'a';

	for (int i = 0;i < 26; i++)
	{
		array[i] = cnt;
		printf("%c\t", array[i]);
		cnt++;
	}
	return 0;
}
```
## 2
```c
#include <stdio.h>

int main(void)
{
	for (int i = 1;i <= 5;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			printf("$");
		}
		printf("\n");
	}
	return 0;
}
```
## 3
```c
#include <stdio.h>

int main(void)
{
	for (char i = 'F'; i >= 'A';i--)
	{
		for (char j = 'F';j >= i; j--)
		{
			printf("%c", j);
		}
		printf("\n");
	}
	return 0;
}
```
## 4
```c
#include <stdio.h>

int main(void)
{
	char cnt1 = 1;

	for(char i = 'A'; i <= 'U'; i+=cnt1)
	{
		for (char j = i-cnt1+1; j <= i; j++)
		{
			printf("%c", j);
		}
		printf("\n");
		cnt1++;
	}
	return 0;
}
```
### 更好的答案(思路清晰):
```c
#include <stdio.h>

int main(void)
{
    int i ,j;
    char c = 'A';
    
    for (i = 1; i <= 6; i++) 
    {

        for (j = 0; j < i; j++)
        {
            printf("%c", c);
            c++;
        }
        printf("\n");
    }
    return 0;
}
```
**本题总结:**

==题目理解:从A到U输出字符,当一行的字符数量等于行号的时候换行.==
 这样可以不用字符控制循环,而改用数字(比较小且和行列数关系密切),最后考虑字符的输出.

- 首先考虑排版:

  比如由`for (i = 1; i <= 6 ; i++)`来控制输出6行,由题知每行输出字母的个数等于行号,所以由`for (j = 0; j < i ; j++)`来控制每行字母的个数.

- 然后考虑字符的输出:

  声明`char c = 'A'`,然后再内循环中,输出一个字母就`c++`,这样每执行一次循环就会往后输出一个字母,每行输出字母的数量已经由`j`控制,到对应位置会自动换行.这样就实现了题目效果.

那么,按照这个思路重新完成第三题.
### 3(better)
```c
#include <stdio.h>

int main(void)
{

	for (int i = 1; i <= 6; i++)
	{
		char c = 'F';//每重新进入一次内循环,从'F'开始输出
		for (int j = 0; j < i; j++)
		{
			printf("%c", c);
			c--;
		}
		printf("\n");
	}
	return 0;
}
```
另一种写法:
```c
int main(void)
{
	int i,j;
	char c;
	for (i = 1; i <= 6; i++)
	{
		for (j = 0,c = 'F'; j < i; j++)
		{
			printf("%c", c);
			c--;
		}
		printf("\n");
	}
	return 0;
}
```
## 5
编程分析:
- 程序应该首先读取用户输入的大写字母,这决定了行数和每行的字母.
- 为了保证以金字塔形状输出,需要合理补充空格.
- 	只有左侧需要补充空格,右侧不用补充即可形成金字塔形状.
- 	左侧补充的空格数=总行数-行数
- 打印时分三部分:
- 	空格
- 	正序字符
- 	逆序字符
```c
#include <stdio.h>

int main(void)
{
	char input;
	scanf_s("%c", &input,1);

	for (char line = 'A';line <= input;line++)
	{
		
		int numberOfSpaces = input - line;
		for (int cnt = 0;cnt < numberOfSpaces;cnt++)
		{
			printf(" ");
		}
		char c;
		for (c = 'A';c < line;c++)
		{
			printf("%c", c);
		}
		for (;c >= 'A';c--)
		{
			printf("%c", c);
		}
		printf("\n");	
	}
	return 0;
}
```

## 6

```c
#include <stdio.h>

int main(void)
{
	int start;
	int end;
	printf("Please enter the start number:");
	scanf_s("%d", &start);
	printf("Please enter the end number:");
	scanf_s("%d", &end);

	printf("   Ori   Square   Cubic\n");
	for (int i = start;i <= end;i++)
	{
		printf("%6d%9d%8d\n", i, i * i, i * i * i);
	}
	return 0;
}
```

## 7

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[30];

	printf("Please enter the world : ");
	scanf_s("%s", word,sizeof(word));

	int len = strlen(word) - 1;
	for (int i = len;i >= 0;i--)
	{
		printf("%c", word[i]);
	}
	return 0;
}
```

## 8

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
	float x, y;;

	printf("Please enter the two float data(Q TO QUIT): ");

	while (scanf_s("%f %f", &x, &y) == 2)
	{
		printf("The answer is %f\n", (x - y) / (x * y));

		printf("Please enter the two float data(Q TO QUIT): ");
	}

	return 0;
}
```

## 12

```c
#include <stdio.h>

int main(void)
{
	int length;
	double sum = 0.0;

	printf("Please enter the limit length:");
	scanf_s("%d", &length);
	while (length > 0)
	{
		sum = 0.0;
		for (int i = 1;i <= length; i++)
		{
			sum = sum + 1.0 / i;
		}
		printf("%lf\n", sum);
		for (int i = 1;i <= length; i++)
		{
			sum = sum + pow(-1, i + 1);
		}
		printf("%lf\n", sum);

		printf("Please enter the limit length:");
		scanf_s("%d", &length);
	}

	return 0;
}
```
## 14
```c
#include <stdio.h>

int main(void)
{
	double first[8];
	double second[8];

	for (int i = 0;i < 8;i++)
	{
		printf("Please assign a value to first array[%d]:", i);
		scanf_s("%lf", &first[i]);
	}
	for (int i = 0;i < 8;i++)
	{
		double sum = 0.0;
		for (int j = 0;j <= i;j++)
		{
			sum += first[j];
		}
		second[i] = sum;
	}

	printf("first:");
	for (int i = 0;i < 8;i++)
	{
		printf("%lf\t", first[i]);
	}

	printf("\nsecond:");
	for (int i = 0;i < 8;i++)
	{
		printf("%lf\t", second[i]);
	}
	return 0;
}
```
