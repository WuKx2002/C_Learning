#include <stdio.h>
int main_1(void)
{
	printf("100���ڵ����������\n");

	int i ;
	int j ;
	int sum = 0;
	
	for (i = 2;i < 100;i++) {
		int n = 1 ;
		for (j = 2;j < i;j++) {
			if (i % j == 0) {
				n = 0;
				break;
			}
		}
		if (n == 1) {
			printf("%d\n", i);
			sum = sum + i;

		}
	}
	printf("100��������������Ϊ%d", sum);
	return 0;
}