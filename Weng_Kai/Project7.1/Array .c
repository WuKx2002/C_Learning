#include<stdio.h>
int main_1(void)
{
	int a[] = { 2,4,6,7,1,3,5,9,11,13,23,14,32 };//����ļ��ɳ�ʼ��
	{
		int i;
		for (i = 0;i < 13;i++) {
			printf("%d\t", a[i]);
		}//����
	}
	return 0;
}