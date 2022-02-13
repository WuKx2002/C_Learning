# getStruct

> **引入:**
>
> C语言没有直接的方式可以scanf一个结构,我们打算写一个函数来读入结构.

如果我们写这样一个函数:

```C
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
    scanf_s("%d %d", &p.x,&p.y);
    printf("%d %d\n", p.x, p.y);
}

void output(struct point p)
{
    printf("%d %d\n", p.x, p.y);
}
```

运行结果:

```
请输入两个整数:3 5
3 5
0 0
```

显然,在`getStruct`中得到的两个整数`3 5`并没有在`output`中输出.

→结构体和数组不同,`p`仅仅是`y`的克隆体,只是又`y`的值而已,与`y`没有联系.

在`getStruct`函数读入`p`的值后,没有任何东西返回到`main`函数,所以`y`还是`{0,0}`.

那么,读入的结构如何传回来呢?==**→注意:C在函数调用时是传值的**==

## 方案一

**在`getStruct`函数中,创建一个临时的结构变量,然后把这个结构返回给调用者**

```C
#include<stdio.h>

struct point {
    int x;
    int y;
};

struct point getStruct(void);
/*原:void getStruct(struct point);
现在我们让getStruct不需要参,而返回一个结构变量函数struct point*/
void output(struct point);

int main(void)
{
    struct point y = { 0,0 };
    y = getStruct();//两个结构变量可以赋值,将getStruct中返回的结构p赋值给y
    output(y);

    return 0;
}

struct point getStruct(void)
{
    struct point p;//本地变量p,在离开这个函数时会消失
    printf("请输入两个整数:");
    scanf_s("%d %d", &p.x,&p.y);
    printf("%d %d\n", p.x, p.y);
    return p;//返回这个结构
}

void output(struct point p)
{
    printf("%d %d\n", p.x, p.y);
}
```
运行结果:

```
请输入两个整数:3 5
3 5
3 5
```

## 方案二

> *K&R* once said,
>
> "If a large structure is to be passed to a function,it is generally more efficient to pass a pointer than to copy the whole structure."

**更推荐:结构指针作为参数传递**

```c
#include<stdio.h>

struct point {
    int x;
    int y;
};

struct point* getStruct(struct point*p);
//结构指针作为参数传入getStruct,结果以指针的形式返回.
void output(struct point);
void print(const struct point* p);

int main(void)
{
    struct point y = { 0,0 };
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));

    return 0;
}

struct point* getStruct(struct point*p)
{
    printf("请输入两个整数:");
    scanf_s("%d %d", &p->x, &p->y);
    printf("%d %d\n", p->x, p->y);
    return p;
}

void output(struct point p)
{
    printf("%d %d\n", p.x, p.y);
}

void print(const struct point* p)
{
    printf("%d %d\n", p->x, p->y);
}
```

运行结果:

```
请输入两个整数:3 5
3 5
3 5
```

