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
    weekend = (enum day)a;  //����ת��
    //weekend = a; //����
    printf("weekend:%d", weekend);
    return 0;
}