#include <stdio.h>
int main(void)
{
	int hour1, minute1;
	int hour2, minute2;
	int total_minute1, total_minute2;
	int minute_difference;
	int hour, minute;

	printf("ʱ�������\n");

	printf("������ǰ���ʱ��(Сʱ+�ո�+���ӣ���");
	scanf("%d %d", &hour1, &minute1);
	
	printf("����������ʱ��(Сʱ+�ո�+���ӣ���");
	scanf("%d %d", &hour2, &minute2);

	total_minute1 = hour1 * 60 + minute1;
	total_minute2 = hour2 * 60 + minute2;
	
	minute_difference = total_minute2 - total_minute1;
	hour = minute_difference / 60;
	minute = minute_difference % 60;

	printf("ʱ���Ϊ��%d Сʱ %d ����",hour,minute);

	return 0;
}