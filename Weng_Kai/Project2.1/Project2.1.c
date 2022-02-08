#include <stdio.h>
int main(void)
{
	double foot;
	double inch;

	//double 双精度浮点数，float 单精度浮点数

	printf("身高转换器\n");
	printf("请输入身高的英尺和英尺，用空格隔开：\n");

	scanf("%lf %lf", &foot, &inch);

	printf("您的身高是%f米。\n",
		((foot + inch / 12) * 0.3048));

}