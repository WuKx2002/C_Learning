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

	printf("ÇëÊäÈëÄãÏ²»¶µÄÑÕÉ«´úÂë:");
	scanf_s("%d", &color);
	if (color >= 0 && color < NumCOLORS) 
	{
		colorName = ColorNames[color];
	}
	else 
	{
		colorName = "unknown";
	}
	printf("ÄãÏ²»¶µÄÑÕÉ«ÊÇ%s\n",colorName);

	return 0;
}