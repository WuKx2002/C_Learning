#include <stdio.h>
#include "hotel.h"

void stars(void)
{
	printf("\n%s%s\n", STARS, STARS);
}

int menu(void)
{
	int code,status;
	char h1[] = "1) Fairfield Arms";
	char h2[] = "2) Hotel Olympic";
	char h3[] = "3) Chertworthy Plaza";
	char h4[] = "4) The Stockton";
	char q[] = "5) QUIT";

	stars();
	
	printf("Hotel List:\n");
	printf("%s\t%s\n"
		"%s\t%s\n"
		"%s\n"
		,h1,h2,h3,h4,q);
	
	stars();

	printf("Please enter the hotel number you intend to stay(1, 2, 3, 4 or 5):");

	while ((status = scanf_s("%d", &code)) != 1 || (code < 1 || code > 5))
	{
		if (status != 1)
		{
			scanf_s("%*s");
		}
		printf("Please enter an integer from 1 to 5: ");
	}

	return code;
}

int getNights(void)
{
	int nights;

	printf("Please enter the number of nights you intend to schedule:");
	while ((scanf_s("%d", &nights)) != 1 )
	{
		scanf_s("*s");
		printf("Please enter an integer: ");
	}
	return nights;
}

void showPrice(int nights,double roomPrice)
{
	double totalPrice = 0;
	double factor = 1.0;

	for (int i = 1;i <= nights;i++)
	{
		totalPrice += roomPrice * factor;
		factor *= DISCOUNT;
	}

	printf("The total price will be $%.2f\n", totalPrice);
}