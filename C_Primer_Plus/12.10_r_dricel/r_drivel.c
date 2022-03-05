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