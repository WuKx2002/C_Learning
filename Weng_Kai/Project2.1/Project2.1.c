#include <stdio.h>
int main(void)
{
	double foot;
	double inch;

	//double ˫���ȸ�������float �����ȸ�����

	printf("���ת����\n");
	printf("��������ߵ�Ӣ�ߺ�Ӣ�ߣ��ÿո������\n");

	scanf("%lf %lf", &foot, &inch);

	printf("���������%f�ס�\n",
		((foot + inch / 12) * 0.3048));

}