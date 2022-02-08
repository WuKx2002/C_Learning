#include <stdio.h>

int main_2()
{
	int i, j, k;
	i = 3;
	j = i++;
	k = ++i;
	printf("%d %d", j, k);

	return 0;
}