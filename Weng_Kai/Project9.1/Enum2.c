#include <stdio.h>

int main(void)
{
    enum day
    {
        Saturday,
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday
    } workday;

    int a = 1;
    enum day weekend;
    weekend = (enum day)a;  //ÀàĞÍ×ª»»
    //weekend = a; //´íÎó
    printf("weekend:%d", weekend);
    return 0;
}