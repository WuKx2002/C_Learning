#include<stdio.h>

enum COLOR { RED, YELLOW, GREEN, NumCOLORS };

int main_1(int argc, char const* argv[])
{
	int color = -1;
	char* ColorNames[NumCOLORS] = 
	{
		"red","yellow","green",
	};
	char* colorName = NULL;

	printf("��������ϲ������ɫ����:");
	scanf_s("%d", &color);
	if (color >= 0 && color < NumCOLORS) 
	{
		colorName = ColorNames[color];
	}
	else 
	{
		colorName = "unknown";
	}
	printf("��ϲ������ɫ��%s\n",colorName);

	return 0;
}