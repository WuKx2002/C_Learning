#include <stdio.h>
int main_1(void)
{
	int num;
	int sum = 0;
	int n = 0;

	printf("����ƽ����������\n");
	printf("����-1���ɽ�������\n");
	printf("�������%d������,��Enter����:",n+1);
	scanf_s("%d", &num);

	while (num != -1) {
		sum += num;
		n++;
		printf("�������%d������,��Enter����:", n + 1);
		scanf_s("%d",&num);

	}
	printf("��%d������ƽ����Ϊ:%f", n + 1, 1.0 * sum / n);

	return 0;
}