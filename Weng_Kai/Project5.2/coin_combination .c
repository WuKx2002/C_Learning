#include <stdio.h>
int main(void) {
	printf("输出1角,2角和5角硬币组成1元的全部组合\n");

	int one, two, five;
	int sum;
	
	for (one = 0;one <= 10;one++) {
		for (two = 0;two <= 5;two++) {
			for (five = 0;five <= 2;five++) {
				sum = one * 1 + two * 2 + five * 5；
				if (sum == 10) {
					printf("%d个1角+%d个2角+%d个5角=1元\n", one, two, five);
				}
			}
		}
	}
	
	return  0;
}