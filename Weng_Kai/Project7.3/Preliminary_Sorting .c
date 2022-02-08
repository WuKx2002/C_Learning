#include<stdio.h>

int max(int a[], int length);

int main(void) 
{
	int a[] = { 2,1,3,4 };
	int length = sizeof(a) / sizeof(a[0]);
	
	for (int i = length - 1;i > 0;i--) {
		int maxid = max(a, i+1);
		int t = a[maxid];
		a[maxid] = a[i];
		a[i] = t;
	}
	for (int i = 0;i < length;i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

int max(int a[], int length)
{
	int maxid = 0;
	for (int i = 1;i < length;i++) {
		if (a[i] > a[maxid]) {
			maxid = i;
		}
	}
	return maxid;
}