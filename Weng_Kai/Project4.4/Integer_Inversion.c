#include <stdio.h>
int main(void)
{
	printf("整数逆序\n");
	int num = 0;
	printf("请输入一个整数:");
	scanf_s("%d", &num);
	//得到一个数的个位数:除以10取余
	int remainder;
	while (num > 0){
		remainder = num % 10;
		printf("%d", remainder);
		num /= 10;
		//去掉一个数的个位数:除以10取整
	}
	return 0;
}