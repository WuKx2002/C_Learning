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