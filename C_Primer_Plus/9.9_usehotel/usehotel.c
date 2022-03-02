#include <stdio.h>
#include "hotel.h"
extern int getNights(void);
int main(void)
{
	int code;
	int nights;
	double roomPrice;

	while (code = menu() != QUIT)
	{
		switch (code)
		{
			case 1:	roomPrice = HOTEL1;
					break;
			case 2:	roomPrice = HOTEL2;
					break;
			case 3:	roomPrice = HOTEL3;
					break;
			case 4:	roomPrice = HOTEL4;
					break;
			default:roomPrice = 0.0;
					printf("OPPS!\n");
					break;
		}
		nights = getNights();
		showPrice(nights,roomPrice);
	}
	printf("Thanks for using.");
	return 0;
}