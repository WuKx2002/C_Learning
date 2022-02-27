#  Chapter10

## 1

```C
/*计算2010~2014年每年的总降水量、年平均降水量和5年中每月的平均降水量*/
#include <stdio.h>
#define MONTHS 12
#define YEARS   5 
int main(void)
{
    const float rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6}, 
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3}, 
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4}, 
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2}, 
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };

    int year,month;
    float total_annual_precipitation = 0;       /*每年的总降水量*/
    float years_average_precipitation = 0;      /*年平均降水量*/
    float monthly_average_precipitation = 0;    /*月平均降水量*/

    const float (*pr)[MONTHS] = rain;

    printf("***********************************************"
            "*********************************************\n");
    printf("year\ttotal_annual_precipitation\n");

    float sum_of_five_years = 0;
    for (year = 0; year < YEARS; year++)
    {
        total_annual_precipitation = 0;
        for (month = 0; month < MONTHS; month++)
        {
           total_annual_precipitation +=  *(*(pr + year) + month);
        }
        sum_of_five_years += total_annual_precipitation;
        printf("%d\t%.2f\n", year + 2010, total_annual_precipitation);
    }
    years_average_precipitation = sum_of_five_years / 5;
    printf("years_average_precipitation : %.2f\n", years_average_precipitation);

    printf("***********************************************"
            "*********************************************\n");

    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");
    sum_of_five_years = 0;
    for (month = 0; month < MONTHS; month++)
    {
        for (year = 0; year < YEARS; year++)
        {
            sum_of_five_years +=  *(*(pr + year) + month);  
        }
        monthly_average_precipitation = sum_of_five_years / 5;
        printf("%.2f\t", monthly_average_precipitation);
    }
    printf("\n***********************************************"
            "*********************************************\n");
    return 0;
}
```

