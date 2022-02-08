#include <stdio.h>
int main(void)
{
	/*
	第一个程序

	int number;
	int n=0;

	printf("正整数位数判断程序\n");

	printf("请输入一个正整数：");
	scanf_s("%d", &number);


	while (number > 0) {
		number /= 10;
		n++;
	}

	printf("这是一个%d位数", n);

	return 0;

	---------------------------------------

	第二个程序

	int number;
	int n=0;

	printf("正整数位数判断程序\n");

	printf("请输入一个正整数：");
	scanf_s("%d", &number);
	
	do {
		number /= 10;
		n++;
	} while (number > 0);

	printf("这是一个%d位数", n);

	*/

	int i = 1;
	int j = 1;
	int n;

	printf("阶乘计算器\n");
	printf("请输入一个正整数：");
	scanf_s("%d", &n);

	while (i <= n) {

		j *= i;
		i++;
	}
	printf("%d!=%d" ,n,j);
}