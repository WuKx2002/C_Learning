#include<stdio.h>
#define PI 3.14
#define MONEY 100
/*�������壺
�궨�壬Ӧ�ô�д*/
int main(void)
{
	int number = 50;
	float money1 = 99.9;
	double money2 = 99.9;//����������double
	/*����������
	1��ֻ���Դ�Сд��ĸ���»��߿�ͷ
	2�����ܻ������ַ�����!@#$%...
	3����������֪�⣨sum��temp��first_name...)
	4���»���������*���շ���������������������*/
	printf("number = %d\n",number);
	printf("money1 = %f\n", money1);
	printf("money2 = %lf\n", money2);
	//%d��ʾʮ�����з��ŵ�����,%f��ʾ������
	printf("MONEY = %d\n", MONEY);
	return 0;
}