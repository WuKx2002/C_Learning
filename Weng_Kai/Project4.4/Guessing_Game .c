#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main_2(void)
{
	srand(time(0));
	int number = rand() % 100 + 1;//得到一个1到100的随机数
	int count = 0;//用于计数
	int a = 0;//初始化用户输入的数
	printf("我已经想好了一个1到100之间的数.\n");
	do {
		printf("请猜一个1到100之间的数:");
		scanf_s("%d", &a);
		count++;
		if (a < number) {
			printf("猜小了.\n");
		}
		else if (a > number) {
			printf("猜大了.\n");
		}
	} while (a != number);
	printf("恭喜你,用了%d次就猜到了正确答案.", count);
	return 0;
}