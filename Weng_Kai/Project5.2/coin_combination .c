#include <stdio.h>
int main(void) {
	printf("���1��,2�Ǻ�5��Ӳ�����1Ԫ��ȫ�����\n");

	int one, two, five;
	int sum;
	
	for (one = 0;one <= 10;one++) {
		for (two = 0;two <= 5;two++) {
			for (five = 0;five <= 2;five++) {
				sum = one * 1 + two * 2 + five * 5��
				if (sum == 10) {
					printf("%d��1��+%d��2��+%d��5��=1Ԫ\n", one, two, five);
				}
			}
		}
	}
	
	return  0;
}