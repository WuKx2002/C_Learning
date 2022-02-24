# 指针、数组与函数（进阶）

## 1.指针与一维数组

我们知道，C语言在描述数组表示法时借助了指针。数组名`a`是该数组首元素的地址，定义`a[n]`的意思是`*(a+n)`.可以认为`*(a+n)`的意思是“到内存的a位置，然后移动n个单元。（在C中，指针+1指的是增加一个存储单元，对数组而言，这意味着+1后的地址是下一个元素的地址。）

一维数组在内存中是依次排列的，如图：



<img src="https://markdown-1309501826.cos.ap-nanjing.myqcloud.com/Typora/C语言/一维数组存储方式.png" style="zoom:30%" />

于是，有:

`a = &a = &a[0]`

`*a = a[0]`

## 2.指针与二维数组

为了示例，我们定义一个二维数组：

```c
int a[3][4] = {
    {0,1,2,3},
    {4,5,6,7},
    {8,9,10,11}
};

/*
等价定义：
int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
*/
```

可以这样理解这个二维数组：

- `a`是一个二维数组。
- `a[0]`是这个二维数组的首元素，`a[1]`是这个二维数组的第二个元素……
- `a[0]`同时是一个包含了`0,1,2,3`四个元素的数组（名），`a[1]`同时是一个包含了`4,5,6,7`四个元素的数组（名）……

- 

二维数组在内存中也是依次排列的，如图：

<img src="https://markdown-1309501826.cos.ap-nanjing.myqcloud.com/Typora/C语言/二维数组存储方式3.png" style="zoom:30%" />

类比一维数组，有如下事实：

- `a`是`a[0]`的地址，即`a`指向`a[0]`。

- `a[0]`是`a[0][0]`的地址，即`a[0]`指向`a[0][0]`。

  也就是说，`a = &a[0] , &a[0] = &a[0][0]`

- 值得注意的是，`&a = a[0] , &a[0] = &a[0][0]` (起始位置相同），因此`a = a[0] = &a = &a[0] = &a[0][0]`。

  也就是说，`a `，`a[0]`，`a[0][0]`都储存在同一地方，如图：

<img src="https://markdown-1309501826.cos.ap-nanjing.myqcloud.com/Typora/C语言/二维数组存储方式4.png" style="zoom:30%" />

使用解引用运算符*访问数组元素：

`*a = a[0]`，`*a[0] = *(*a) = a[0][0]`

`*(a+1) = a[1]`，` *a[1] = *(a+1) = a[1][0]`

`*(a+1) + 2 = a[1] + 2 = a[1][2]`

## 3. 指向数组的指针

### （1）指向一维数组的指针

#### 	①a是一维数组

```c
#include <stdio.h>

int main(void)
{
    int a[3] = {12, 14, 16};
    int * p = a;

    printf("p = %d\t", p);
    printf("a = %d\n", a);
    printf("&p = %d\t", &p);
    printf("&a = %d\n", &a);
    printf("*p = %d\t\t", *p);
    printf("*a = %d\n", *a);

    return 0;
}
```

输出：

```
p = 6422036     a = 6422036
&p = 6422024    &a = 6422036
*p = 12         *a = 12
```

==**❗ 普通指针指向数组，实际上是指向数组的第一个元素，*用来访问这个元素。**==

`p`指向数组`a`，也就是指向`a[0]`。所以`*p = *a = a[0]`。

#### 	②a是二维数组

```c
#include <stdio.h>

int main(void)
{
    int a[2][2] = {12, 14, 16};
    int * p = a[0];

    printf("p = %d\t", p);
    printf("a = %d\n", a);
    printf("&p = %d\t", &p);
    printf("&a = %d\n", &a);
    printf("*p = %d\t\t", *p);
    printf("*a[0] = %d\n", *a[0]);

    return 0;
}
```

输出：

```
p = 6422032     a = 6422032
&p = 6422024    &a = 6422032
*p = 12         *a[0] = 12
```

在这个例子中，虽然`p`仍然指向一维数组，但是`a`是一个二维数组，这就涉及到解引用运算符层级的问题。

==**❗ 普通指针指向数组，实际上是指向数组的第一个元素，*用来访问这个元素。**==

`p`指向`a[0]`，也就是指向`a[0][0]`，所以`*p  = *a[0] = a[0][0]`。

###（2）指向二维数组的指针

```c
#include <stdio.h>

int main(void)
{
    int a[2][2] = {12, 14, 16};
    int (* p)[2] = a;//p指向一个内含两个int类型值的数组a[0]

    printf("p = %d\t", p);
    printf("a = %d\n", a);
    printf("&p = %d\t", &p);
    printf("&a = %d\n", &a);
    printf("*p = %d\t", *p);
    printf("*a = %d\n", *a);
    printf("a[0] = %d\n", a[0]);
    return 0;
}
```

输出：

```
p = 6422032     a = 6422032
&p = 6422024    &a = 6422032
*p = 6422032    *a = 6422032
a[0] = 6422032
```

==**❗ 普通指针指向数组，实际上是指向数组的第一个元素，*用来访问这个元素。**==

`p`指向二维数组`a`,实际上是指向二维数组第一个元素`a[0]`，所以`*p = *a = a[0] `。

下面用《C Primer Plus》中的例子演示指向二维数组的指针的应用：

```c
#include <stdio.h>
int main(void)
{
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
    int (*pz)[2];
    pz = zippo;
    
    printf("   pz = %p,    pz + 1 = %p\n",
           pz,         pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
           pz[0],      pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n",
           *pz,        *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));
    
    return 0;
}
```

输出：

```
   pz = 000000000061FDF0,    pz + 1 = 000000000061FDF8
pz[0] = 000000000061FDF0, pz[0] + 1 = 000000000061FDF4
  *pz = 000000000061FDF0,   *pz + 1 = 000000000061FDF4
pz[0][0] = 2
  *pz[0] = 2
    **pz = 2
      pz[2][1] = 3
*(*(pz+2) + 1) = 3
```

即`pz[m][n] == *(*(pz + m) + n)`

## 4.函数与一维数组

声明一维数组形参：

因为数组名是数组首元素的地址，作为实际参数的数组名要求形式参数是一个与之匹配的指针。在这种情况下，C把`int a[]`和`int * a`解释成一样。也就是说，`a`是指向`int`的指针。

由于函数原型可以省略参数名，所以下面四种原型是等价的：

```c
int f(int a[]);
int f(int [])
int f(int *a);
int f(int *);
```

但是，在函数定义中不能省略参数名。下面两种定义是等价的：

```c
int f(int a[])
{
    ...
}
int f(int *a);
{
    ...
}
```

## 5.函数与二维数组

下面我们在实例中介绍二维数组作为形式参数的声明和定义：

```c
#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
/*
等价声明：
void sum_rows(int [][COLS], int rows);//省略参数名
void sum_rows(int (*ar)[COLS], int rows);//指针定义，ar是一个指向内含4个int数组的指针
void sum_rows(int (*)[COLS], int rows);//也可以省略参数名
*/

int main(void)
{
    int junk[ROWS][COLS] = {
        {2,4,6,8},
        {3,5,7,9},
        {12,10,8,6}
    };
    
    sum_rows(junk, ROWS);
    
    return 0;
}

void sum_rows(int ar[][COLS], int rows)//不能省略参数名
{
    int r;
    int c;
    int tot;
    
    for (r = 0; r < rows; r++)
    {
        tot = 0;
        for (c = 0; c < COLS; c++)
        {
            tot += ar[r][c];
        }
        printf("row %d: sum = %d\n", r, tot);
    }
}
/*
等价定义：
void sum_rows(int(*ar)[COLS], int rows)
{
	...
}
*/
```

==在定义和声明时，也可以在第一个方括号中写上大小，但是编译器会忽略该值。==

一般而言，声明一个指向N维数组的指针，只能省略最左边方括号中的值，因为第一对方括号只用于表明这是一个指针，而其他的方括号则用于描述指针所指数据对象的类型。
