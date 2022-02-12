

# Pointer_Basics

## **1.取地址运算**

```C
#include <stdio.h>

int main(void)
{
	int a;
	a = 100;
	printf("sizeof(int)=%ld\n", sizeof(int));
	printf("sizeof(a)=%ld\n", sizeof(a));
	//%ld 表示按 long int 格式（有符号长整型数格式）输出.
	return 0;
}
```

输出

```
sizeof(int)=4
sizeof(a)=4
```

即`int`在内存当中占4个字节(4*8=32比特)

![image-20220210165520846](C:\Users\Wu Kaixiang\AppData\Roaming\Typora\typora-user-images\image-20220210165520846.png)

**取地址运算符 & ,获得变量的地址,操作数必须是变量**

```C
#include <stdio.h>

int main(void)
{
    int i = 0;

    printf("i的地址: %p\n", &i);
    /*%p一般以十六进制整数方式输出指针的值，附加前缀0x.(实测VS2020未加)*/
    printf("sizeof(&i) = %lu\n", sizeof(&i));

    int p;
    p = (int)&i;
    //把i的地址强制转换为int类型并赋值给p.
    
    printf("int p = %x\n", p);
    printf("sizeof(int) = %lu\n", sizeof(int));
    //％x以十六进制数形式输出整数,%lu(long unsigned).
    return 0;
}
```

32位架构输出

```
i的地址: 007EFB50
sizeof(&i) = 4
int p = 7efb50
sizeof(int) = 4
```

在32位架构下,`i`的地址 = `int p` ,且`i`的地址的大小 = `int`的大小

64位结构输出

```
i的地址: 0000003E6C33FC00
sizeof(&i) = 8
int p = 6c33fc00
sizeof(int) = 4
```

在32位架构下,`i`的地址不等于 `int p` ,且`i`的地址的大小不等于 `int`的大小

==**→地址的大小是否与``int``相同与架构有关**==

---

### 取`int`类型的地址

```C
#include <stdio.h>

int main(void)
{
    int i = 0;
    int p;

    printf("%p\n", &i);
    printf("%p\n", &p);
    return 0;
}
```

32位架构输出:

```
00B8FEE4
00B8FEE0
```

相差4,也就是一个int.

64位架构输出:

```
0000008AFDBBF7D0
0000008AFDBBF7D4
```

相差4,同样也是一个int.(int类型在32位和64位都占4字节)

![image-20220210171916328](C:\Users\Wu Kaixiang\AppData\Roaming\Typora\typora-user-images\image-20220210171916328.png)

---

### 取数组的地址

```C
#include <stdio.h>

int main(void)
{
    int a[10];

    printf("%p\n", &a);
    printf("%p\n", a);
    printf("%p\n", &a[0]);
    printf("%p\n", &a[1]);

    return 0;
}
```

32位架构输出:

```
00AFF724
00AFF724
00AFF724
00AFF728
```

64位架构输出:

```
00000050AE4FFE80
00000050AE4FFE80
00000050AE4FFE80
00000050AE4FFE84
```

可以发现, `&a` = `a` =` &a[0]` ,`&a[1]`比`&a[0]`大4	**即数组相邻单元地址差4.**

## **2.指针**

```C
int i;
int* p = &i;
```

```c
int i;
int* p;
p = &i;
```

星号是用来指定一个变量是指针,需要注意`int* p,q`和`int *p,q`含义相同,都仅表示p是指针,指向int类型的变量,q是普通int类型的变量.

**指针变量的值是具有实际值的变量的地址.**

![img](https://www.runoob.com/wp-content/uploads/2014/09/c-pointer.png)

---

### 作为参数的指针

`void f(int *p);`在被调用的时候得到了某个变量的地址

`int i= 0; f(&i);`在函数里面可以通过这个指针访问外面这个`i`

```C
#include <stdio.h>

void f(int* p);

int main(void)
{
    int i = 6;
    printf("&i = %p\n", &i);

    f(&i);

    return 0;
}

void f(int* p)
{
    printf("p = %p\n", p);
}
```

32位架构输出:

```
&i = 012FFE08
p = 012FFE08
```

---

### 访问地址上的变量

***是一个单目运算符,用来访问指针的值所表示的地址上的变量.**

可以做左值,也可以做右值

例如	`int k = *p;`	`*p = k+1;`

```C
#include <stdio.h>

void f(int* p);

int main(void)
{
    int i = 6;
    printf("&i = %p\n", &i);

    f(&i);

    printf("new i = %d", i);

    return 0;
}

void f(int* p)
{
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    *p = 26;//*p访问了p所指的那个地址(i的地址)上的变量i,并给i赋予了新值.
}
```

32位架构输出:

```
&i = 00EFF8C0   	//i的地址
p = 00EFF8C0  		//i的地址
*p = 6  			//i的值
new i = 26  		//i的新值
```

##  3.指针与数组

```c
#include <stdio.h>

void f(int a[]);//数组作为参数传入函数

int main(void)
{
    int a[] = { 0,1,2,3,4,5,6,7,8,9 };

    printf("main sizeof(a) = %lu\n", sizeof(a));
    printf("main &a = %p\n", a);//直接用a即可取得地址( &a = a = &a[0])

    f(a);

    return 0;
}

void f(int a[])
{
    printf("f sizeof(a) = %lu\n", sizeof(a));
    printf("f a = %p\n", a);
    a[0] = 1000;
}
```

32位架构输出:

```
main sizeof(a) = 40
main &a = 0053FD68
f sizeof(a) = 4
f a = 0053FD68
```

`f a` = `main &a`,说明`f`函数里面的数组和`main`函数里面的数组是同一个数组,且直接用`a`即可取出数组地址.

在`f`函数中更改`a[0]`的值,`main`函数中运行完`f`函数后查看`a[0]`发现`a[0]`被改写.

==→实际上,函数参数表中的数组是指针==

而`int`类型的指针占4字节,故`f sizeof(a)=4`,不等于`main sizeof(a)`.

因此,以下四种<u>函数原型</u>是等价的:

```c
int f(int *a);
int f(int *);
int f(int a[]);
int f(int []);
```

==→数组变量是特殊的指针==

```C
int a[10];
int *p1 = a;
int *p2 = a[1];
```

数组变量本身表达地址,所以无需用"&"取地址.

但是数组的单元表达的是变量,需要用"&"取地址.

---

**[ ]运算符可以对数组做,也可以对指针做.**

`p[0] `等价于`a[0]`

```c
#include <stdio.h>

int main(void)
{
    int a[10] = { 2 };
    int* p = a;
    printf("p[0] = %d\n", p[0]);
    return 0;
}
```

输出:

```
p[0] = 2
```

---

***运算符可以对指针做,也可以对数组做.**

`*a = 1`实际上是给`a[0]`赋值为1

```c
#include <stdio.h>

int main(void)
{
    int a[] = { 0 };
    printf("%d\n", a[0]);

    *a = 1;
    printf("%d\n", a[0]);
    return 0;
}
```

输出:

```
0
1
```

---

**数组变量是const的指针,所以不能被赋值.**

`int b[]`→`int * const b`

> **const 关键字**
>
> 可以使用 **const** 前缀声明指定类型的常量，如下所示：
>
> ```c
> const int a = 5;
> // const 关键字
> // int 数据类型
> // a 变量名
> ```
>
> const 声明常量要在一个语句内完成：
>
> ```
> const int a = 5; √
> 
> const int a;     ×       
> 
> const int a;
> a = 5;           ×
> ```
