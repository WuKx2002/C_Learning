#include<stdio.h>
#define PI 3.14
#define MONEY 100
/*常量定义：
宏定义，应该大写*/
int main(void)
{
	int number = 50;
	float money1 = 99.9;
	double money2 = 99.9;//浮点数常用double
	/*变量命名：
	1、只能以大小写字母和下换线开头
	2、不能换特殊字符，如!@#$%...
	3、做到见名知意（sum、temp、first_name...)
	4、下划线命名法*、驼峰命名法、匈牙利命名法*/
	printf("number = %d\n",number);
	printf("money1 = %f\n", money1);
	printf("money2 = %lf\n", money2);
	//%d表示十进制有符号的整数,%f表示浮点数
	printf("MONEY = %d\n", MONEY);
	return 0;
}