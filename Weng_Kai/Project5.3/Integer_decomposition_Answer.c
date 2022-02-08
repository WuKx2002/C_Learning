#include <stdio.h>
int main_3(void)
{
	int x;
	scanf_s("%d", &x);

	int n = 1;
	int t = x;

	while (t > 9) {
		t /= 10;
		n *= 10;
	}
	printf("x=%d,n=%d\n", x, n);
	do {
		int d = x / n;
		printf("%d", d);
		if (n > 9) {
			printf(" ");
		}
		x %= n;
		n /= 10;
	} while (n > 0);
	printf("\n");

	return 0;
}