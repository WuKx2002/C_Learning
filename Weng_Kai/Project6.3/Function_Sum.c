#include <stdio.h>

void sum(int begin, int end);

int main_1(void)
{
	sum(10, 20);
	sum(20, 25);
	return 0;
}

void sum(int begin, int end)
{
	int i;
	int sum = 0;
	for (i = begin;i < end;i++) {
		sum += i;
	}
	printf("从%d加到%d等于%d\n", begin, end, sum);
}