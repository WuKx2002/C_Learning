#include<stdio.h>
int main(void)
{
	printf("素数检查器\n请输入一个整数:");
	int num;
	int i;
	int n=1;
	scanf_s("%d", &num);
	for (i = 2;i < num;i++) {
		if (num % i == 0) {
			n=0;
			break;//break:跳出循环-->节约资源.
		}
	}
	if (n == 0) {
		printf("这不是一个素数");
	}else{ printf("这是一个素数"); }

}