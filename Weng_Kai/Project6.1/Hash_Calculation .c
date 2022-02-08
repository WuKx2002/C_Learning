#include <stdio.h>
int main(void)
{
	printf("Hash Caculation\n");

	const int number = 10;//数组的大小
	int x;
	int count[10];//定义数组
	int i;
	for (i = 0; i < number; i++) {
		count[i] = 0;//初始化数组
	}
	scanf_s("%d", &x);
	while (x != -1) {
		if (x >= 0 && x <= 9) {
			count[x]++;//数组参与运算
		}
		scanf_s("%d", &x);
	}
	for (i = 0;i < number;i++) {
		printf("%d:%d\n", i, count[i]);//遍历数组输出
	}
	return 0;
}