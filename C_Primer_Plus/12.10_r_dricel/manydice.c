#include <stdio.h>
#include <stdlib.h> //Ϊ�⺯��srand()��rand()�ṩԭ��
#include <time.h>	//Ϊ�⺯��time()�ṩԭ��
#include "dicroll.h"//Ϊroll_n_dice()�ṩԭ�ͣ�Ϊroll_count�ṩ����

int main(void)
{
	int sides;
	int status;
	int dice;

	srand((unsigned int)time(0));//�������
	fputs("Enter the number of sides per die, 0 to stop.\n", stdout);
	while (scanf_s("%d", &sides) == 1 && sides > 0)//������֤
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
					continue;//����������Ĵ�������
				fputs("How many dice ? Enter 0 to stop.\n", stdout);
				continue;//���»ص�ѭ������ȡ����
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