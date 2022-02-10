#include <stdio.h>

void f(int a[]);

int main(void)
{
    int a[] = { 0 };
    printf("%d\n", a[0]);

    *a = 1;
    printf("%d\n", a[0]);
    return 0;
}

void f(int a[])
{
    printf("f sizeof(a) = %lu\n", sizeof(a));
    printf("f &a = %p\n", a);
    a[0] = 1000;
}