#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_2(void)
{
	srand(time(0));
	int number = rand() % 100 + 1;//�õ�һ��1��100�������
	int count = 0;//���ڼ���
	int a = 0;//��ʼ���û��������
	printf("���Ѿ������һ��1��100֮�����.\n");
	do {
		printf("���һ��1��100֮�����:");
		scanf_s("%d", &a);
		count++;
		if (a < number) {
			printf("��С��.\n");
		}
		else if (a > number) {
			printf("�´���.\n");
		}
	} while (a != number);
	printf("��ϲ��,����%d�ξͲµ�����ȷ��.", count);
	return 0;
}