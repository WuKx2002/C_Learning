#include <stdio.h>
int main_1(void)
{
	int x;
	double sum = 0;
	int cnt = 0;
	int number[100];//��������
	scanf_s("%d", &x);
	while (x != 1) {
		number[cnt] = x;//�������е�Ԫ�ظ�ֵ
		//
		{
			int i;
			printf("%d\t", cnt);
			for (i = 0;i <= cnt;i++) {
				printf("%d\t", number[i]);
			}
			printf("\n");
		}
		//
		sum += x;
		cnt++;
		scanf_s("%d", &x);
	}
	if (cnt > 0) {
		int i;
		double average = sum / cnt;
		for (i = 0;i < cnt;i++) {
			if (number[i] > average) {
				printf("%d", number[i]);//ʹ�������е�Ԫ��,��������
			}
		}
	}
	return 0;
}