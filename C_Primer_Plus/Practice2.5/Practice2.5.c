#include <stdio.h>
#define NAME "Wu Kaixiang"
#define Add "Tonghua,Jilin"
#define DAYS_IN_A_YEAR 365

int Br(void);
int Ic(void);


int main(void)
{
    printf("%s\n", NAME);
    printf("%s\n", Add);

    int age = 20;
    int days = age * DAYS_IN_A_YEAR;
    printf("Your age is %d,and it is %d days.\n", age, days);
    
    Br();
    printf(",");
    Ic();
    printf("\n");
    Ic();
    printf("\n");
    Br();
    printf("\n");

    int toes = 10;
    printf("The Variable toes = %d.\n", toes);
    printf("Double toes = %d.\n", 2*toes);
    printf("toes' square = %d.\n", toes*toes);
    return 0;
}

int Br(void)
{
    printf("Brazil,Russia");
    return 0;
}

int Ic(void)
{
    printf("India,China");
    return 0;
}
