#include <stdio.h>
int main(void)
{
	double prize;
	double bill;
	double change;

	printf("���������\n");

	printf("������Ӧ���ܶ");
	scanf_s("%lf", &prize);

	printf("������ʵ���ܶ");
	scanf_s("%lf", &bill);

	change = bill - prize;
	if (change > 0) {
		printf("������%lf", change);
	}
	else if (change == 0) {
		printf("��������");
	}
	else 
		printf("��֧���Ľ��㣬�貹��%lf", -change);
	
	
	return 0;
}