#include<stdio.h>
int main(void)
{
	printf("���������\n������һ������:");
	int num;
	int i;
	int n=1;
	scanf_s("%d", &num);
	for (i = 2;i < num;i++) {
		if (num % i == 0) {
			n=0;
			break;//break:����ѭ��-->��Լ��Դ.
		}
	}
	if (n == 0) {
		printf("�ⲻ��һ������");
	}else{ printf("����һ������"); }

}