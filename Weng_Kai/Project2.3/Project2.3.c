#include <stdio.h>
int main(void)
{
	int hour1, minute1;
	int hour2, minute2;
	int total_minute1, total_minute2;
	int minute_difference;
	int hour, minute;

	printf("时差计算器\n");

	printf("请输入前面的时间(小时+空格+分钟）：");
	scanf("%d %d", &hour1, &minute1);
	
	printf("请输入后面的时间(小时+空格+分钟）：");
	scanf("%d %d", &hour2, &minute2);

	total_minute1 = hour1 * 60 + minute1;
	total_minute2 = hour2 * 60 + minute2;
	
	minute_difference = total_minute2 - total_minute1;
	hour = minute_difference / 60;
	minute = minute_difference % 60;

	printf("时间差为：%d 小时 %d 分钟",hour,minute);

	return 0;
}