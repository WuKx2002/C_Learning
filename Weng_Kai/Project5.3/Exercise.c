#include <stdio.h>
int main_4(void) {
	printf("整数分解\n");
	printf("请输入一个整数:");
	int i;
	scanf_s("%d", &i);

	int j = i;
	int n = 1;
	while (j > 9) {
		j /= 10;
		n *= 10;
	}
	printf("i=%d,n=%d\n", i, n);

	
	do {
		int k = i / n;
		printf("%d", k);
		if (k > 9); {
			printf(" ");
		}
		i %= n;
		n /= 10;
	} while (n > 0);
	return 0;
}