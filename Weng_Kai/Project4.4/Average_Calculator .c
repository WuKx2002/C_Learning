#include <stdio.h>
int main_1(void)
{
	int num;
	int sum = 0;
	int n = 0;

	printf("整数平均数计算器\n");
	printf("输入-1即可结束程序\n");
	printf("请输入第%d个整数,按Enter结束:",n+1);
	scanf_s("%d", &num);

	while (num != -1) {
		sum += num;
		n++;
		printf("请输入第%d个整数,按Enter结束:", n + 1);
		scanf_s("%d",&num);

	}
	printf("这%d整数的平均数为:%f", n + 1, 1.0 * sum / n);

	return 0;
}