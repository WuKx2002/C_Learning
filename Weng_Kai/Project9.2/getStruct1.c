#include<stdio.h>

struct point {
    int x;
    int y;
};

void getStruct(struct point);
void output(struct point);

int main(void)
{
    struct point y = { 0,0 };
    getStruct(y);
    output(y);

    return 0;
}

void getStruct(struct point p)
{
    printf("请输入两个整数:");
    scanf_s("%d %d", &p.x, &p.y);
    printf("%d %d\n", p.x, p.y);
}

void output(struct point p)
{
    printf("%d %d\n", p.x, p.y);
}