# Chapter 5
## 1

```c
#include <stdio.h>

int main(void)
{
	const int MINUTE_PER_HOUR = 60;
	int input;

	printf("Please input the number of minutes(<=0 to quit):");
	scanf_s("%d", &input);

	while(input> 0)
	{
		int hours = input / MINUTE_PER_HOUR;
		int minutes = input % MINUTE_PER_HOUR;

		printf("%d = %d hour(s) %d minute(s)\n", input, hours, minutes);

		printf("Please input the number of minutes(<=0 TO QUIT):");
		scanf_s("%d", &input);
	} 

	printf("Thanks for using.");
	return 0;
}
```
## 2

```c
#include <stdio.h>

int main(void)
{
	int input;

	printf("Please input a number:");
	scanf_s("%d", &input);

	int cnt = 0;

	while (cnt++ <= 10)
	{
		printf("%d\n", input++);
	}
	return 0;
}
```
## 7

```c
#include <stdio.h>

int main(void)
{
	double input;
	void cubic(double n);
	printf("Please enter the double datum to calc cubic:");
	scanf_s("%lg", &input);
	cubic(input);
	//%lg是根据结果自动选择小数计数还是指数计数的转换说明.
	return 0;
}

void cubic(double n)
{
	double result = n * n * n;
	printf("The %lg's cubic is %lg !\n", n, result);
}
```
