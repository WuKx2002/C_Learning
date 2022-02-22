# Chapter 9
## 9.8

> 递归

**案例:十进制整数转换成二进制**

**算法:除2取余,倒序输出**

```c
#include <stdio.h>

void to_Binary(unsigned long num);

int main(void)
{
	unsigned long num;

	printf("Please enter an integer(q to quit):");

	while (scanf_s("%lu", &num) == 1)
	{
		printf("Binary Equivalent:");
		to_Binary(num);
		printf("\nPlease enter an integer(q to quit):");
	}
	printf("Done!");

	return 0;
}

void to_Binary(unsigned long num)
{
	int array[40]={0};
	int i = 0;
	while (num > 0)
	{
		int output = num % 2;

		array[i++] = output;
		num /= 2;
	}
	for (int j = i;j >= 0;j--)
	{
		printf("%d", array[j]);
	}
}
```
递归算法:
```c

/* binary.c -- prints integer in binary form */
#include <stdio.h>
void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;
    printf("Enter an integer (q to quit):\n");
    while (scanf("%lu", &number) == 1)
    {
        printf("Binary equivalent: ");
        to_binary(number);
        putchar('\n');
        printf("Enter an integer (q to quit):\n");
    }
    printf("Done.\n");
    
    return 0;
}

void to_binary(unsigned long n)   /* recursive function */
{
    int r;
    
    r = n % 2;
    if (n >= 2)
        to_binary(n / 2);
     putchar(r == 0 ? '0' : '1');
    
    return;
}
```
## 9.9-11
usehotel.c
```c
#include <stdio.h>
#include "hotel.h"

int main(void)
{
	int code;
	int nights;
	double roomPrice;

	while (code = menu() != QUIT)
	{
		switch (code)
		{
			case 1:	roomPrice = HOTEL1;
					break;
			case 2:	roomPrice = HOTEL2;
					break;
			case 3:	roomPrice = HOTEL3;
					break;
			case 4:	roomPrice = HOTEL4;
					break;
			default:roomPrice = 0.0;
					printf("OPPS!\n");
					break;
		}
		nights = getNights();
		showPrice(nights,roomPrice);
	}
	printf("Thanks for using.");
	return 0;
}
```
hotel.c
```c
#include <stdio.h>
#include "hotel.h"

void stars(void)
{
	printf("\n%s%s\n", STARS, STARS);
}

int menu(void)
{
	int code,status;
	char h1[] = "1) Fairfield Arms";
	char h2[] = "2) Hotel Olympic";
	char h3[] = "3) Chertworthy Plaza";
	char h4[] = "4) The Stockton";
	char q[] = "5) QUIT";

	stars();
	
	printf("Hotel List:\n");
	printf("%s\t%s\n"
		"%s\t%s\n"
		"%s\n"
		,h1,h2,h3,h4,q);
	
	stars();

	printf("Please enter the hotel number you intend to stay(1, 2, 3, 4 or 5):");

	while ((status = scanf_s("%d", &code)) != 1 || (code < 1 || code > 5))
	{
		if (status != 1)
		{
			scanf_s("%*s");
		}
		printf("Please enter an integer from 1 to 5: ");
	}

	return code;
}

int getNights(void)
{
	int nights;

	printf("Please enter the number of nights you intend to schedule:");
	while ((scanf_s("%d", &nights)) != 1 )
	{
		scanf_s("*s");
		printf("Please enter an integer: ");
	}
	return nights;
}

void showPrice(int nights,double roomPrice)
{
	double totalPrice = 0;
	double factor = 1.0;

	for (int i = 1;i <= nights;i++)
	{
		totalPrice += roomPrice * factor;
		factor *= DISCOUNT;
	}

	printf("The total price will be $%.2f\n", totalPrice);
}
```
hotel.h
```c
#define HOTEL1		180.00
#define HOTEL2		225.00
#define HOTEL3		2255.00
#define HOTEL4		355.00
#define DISCOUNT	0.95
#define QUIT		5
#define STARS		"**************************************************"

void stars(void);//产生星号线

int menu(void);//显示菜单并读取输入的酒店号

int getNights(void);//获得用户预定天数

void showPrice(int nights,double roomPrice);//计算总价
```


## 5

