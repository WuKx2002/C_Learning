#include <stdio.h>
int main(void)
{
	printf("��������\n");
	int num = 0;
	printf("������һ������:");
	scanf_s("%d", &num);
	//�õ�һ�����ĸ�λ��:����10ȡ��
	int remainder;
	while (num > 0){
		remainder = num % 10;
		printf("%d", remainder);
		num /= 10;
		//ȥ��һ�����ĸ�λ��:����10ȡ��
	}
	return 0;
}