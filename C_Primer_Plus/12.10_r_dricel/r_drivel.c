#include <stdio.h>
#include <stdlib.h> //Ϊ�⺯��srand()��rand()�ṩԭ��
#include <time.h>	//Ϊ�⺯��time()�ṩԭ��
#include "dicroll.h"//Ϊroll_n_dice()�ṩԭ�ͣ�Ϊroll_count�ṩ����

int roll_count = 0; //��̬�ⲿ����

static int rollem(int sides) //����ÿ���������������̬�ڲ����ӣ�����Ϊ���ļ�˽�С�
{
	int roll;

	roll = rand() % sides + 1;
	roll_count++;

	return roll;
}

int roll_n_dice(int dice, int sides)//������������֮�͡�
{
	int total = 0;
	int ret = 0;//����ֵ��һ���ڡ�

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