#include <stdio.h>
int main_2(void)
{
	int x;

	printf("整数分解\n");
	printf("请输入一个整数:");
	scanf_s("%d", &x);
	/*
	怎么得到一个数的最高位 ?
		12345 / 10000 = 1
	什么时候停止
	剩下的数2345怎么得到?
		12345%10000=2345
	那么,怎么得到10000?
		设置一个计数器,判断12345的位数:5位,然后10*10*10*10=10000
	*/
	//计数器部分:
	int n = 1;
	int count = 0;
	int y = x;//记录用户输入的x的值
	int z = x;//记录用户输入的x的值

	while (y > 0) {
		while (y > 0) {
			y /= 10;
			count++;
			if (count > 1) {
				n *= 10;
			}
		}
		printf("%d ", z / n);
		z %= n;
		y = z;
		n = 1;
		count = 0;
		}
	return 0;
}