#include <stdio.h>
int main(void)
{
	/*
	��һ������

	int number;
	int n=0;

	printf("������λ���жϳ���\n");

	printf("������һ����������");
	scanf_s("%d", &number);


	while (number > 0) {
		number /= 10;
		n++;
	}

	printf("����һ��%dλ��", n);

	return 0;

	---------------------------------------

	�ڶ�������

	int number;
	int n=0;

	printf("������λ���жϳ���\n");

	printf("������һ����������");
	scanf_s("%d", &number);
	
	do {
		number /= 10;
		n++;
	} while (number > 0);

	printf("����һ��%dλ��", n);

	*/

	int i = 1;
	int j = 1;
	int n;

	printf("�׳˼�����\n");
	printf("������һ����������");
	scanf_s("%d", &n);

	while (i <= n) {

		j *= i;
		i++;
	}
	printf("%d!=%d" ,n,j);
}