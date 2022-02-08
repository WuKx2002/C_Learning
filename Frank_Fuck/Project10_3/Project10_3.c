#include <stdio.h>
int main(void)
{
    /*
    int i;
    int j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d*%d=%2d\t", i, j, i * j);
        }
        printf("\n");
}
    */
    /*
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 9; j++)
        {
            if (i >= j)
            {
                printf("%d*%d=%2d\t", i, j, i * j);
            }else{ printf(""); }

        }
        printf("\n");
    }
    return 0;
}
*/
    
    for (int j = 1;j <= 9;j++)
    {
        for (int i = 1;i <= 9;i++)
        {
            if (i <= j) {
                printf("% d*%d=%2d\t", i, j, i * j);
            } 
        } 
        printf("\n");
    }
}