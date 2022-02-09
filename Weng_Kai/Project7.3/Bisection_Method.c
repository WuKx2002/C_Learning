#include<stdio.h>

int search(int k, int a[], int len)
{
	int ret = -1;
	int left = 0;
	int right = len - 1;

	while(right > left)
	{
		int mid = (left + right) / 2;
		if (a[mid] = k) 
		{
			ret = mid;
			break;
		}else if (a[mid] > k) 
		{
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ret;
}

int main(void)
{
	int a[] = { 1,1,2,3,5,8,13,21,34,55,89 };
	int len = sizeof(a) / sizeof(a[0]);
	int k;
	printf("请输入要查找的数:");
	scanf_s("%d",&k);

	int ret = search(k, a, len);
	if (ret == -1)
	{
		printf("未找到");
	}
	else {
		printf("成功找到%d", k);
	}
	return 0;
}