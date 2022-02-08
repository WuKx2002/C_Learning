#include <stdio.h>
int main(void)
{
	double prize;
	double bill;
	double change;

	printf("找零计算器\n");

	printf("请输入应付总额：");
	scanf_s("%lf", &prize);

	printf("请输入实付总额：");
	scanf_s("%lf", &bill);

	change = bill - prize;
	if (change > 0) {
		printf("找您：%lf", change);
	}
	else if (change == 0) {
		printf("无需找零");
	}
	else 
		printf("您支付的金额不足，需补交%lf", -change);
	
	
	return 0;
}