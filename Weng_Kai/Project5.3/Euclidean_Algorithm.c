/*շת��������㹫ʽ:gcd(a,b) = gcd(b,a mod b)*/
#include <stdio.h>
int main_1(void)
{
	int a,b,c;

	printf("��������������:");
	scanf_s("%d %d", &a, &b);
	
	while (b != 0) {
			c = b;
			b = a % b;
			a = c;
		}
		printf("%d", a);
	
	

	return 0;
}