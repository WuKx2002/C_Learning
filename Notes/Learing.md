# 标题1

**强调内容**

## 标题2

*斜体*

~~删除线~~

1. 有序列表
2. Enter直接生成后面序号

+ 无序列表Ctrl+T

|      |      |      |
| ---- | ---- | ---- |
|      |      |      |
|      |      |      |

| 单元1 | 单元2 | 单元3 |
| ----- | ----- | ----- |
|       |       |       |

---

***

本地图片直接拖入



![OIP](C:\Users\Wu Kaixiang\Desktop\OIP.jpg)

插入网络图片：![图片标题](图片链接)

![github](https://logosmarcas.net/wp-content/uploads/2020/12/GitHub-Logo.png)



链接 [链接提示]+(链接地址)
$$
y=kx+b
$$


代码块(判断素数)

~~~c
#include<stdio.h>

int max(int a[], int length);

int main(void) 
{
	int a[] = { 5,9,1,6,8,4,3,7,2 };
	int length = sizeof(a) / sizeof(a[0]);
	
	for (int i = length - 1;i > 0;i--) {
		int maxid = max(a, length);
		int t = a[maxid];
		a[maxid] = a[i];
		a[i] = t;
	}
	for (int i = 0;i < length;i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

int max(int a[], int length)
{
	int maxid = 0;
	for (int i = 1;i < length;i++) {
		if (a[i] > a[maxid]) {
			maxid = i;
		}
	}
	return maxid;
}
for (int i = length - 1;i > 0;i--) {
	int maxid = max(a, length);
	int t = a[maxid];
	a[maxid] = a[i];
	a[i] = t;
}
for (int i = 0;i < length;i++) {
	printf("%d ", a[i]);
}
return 0;
~~~

行内代码`int i = 0`



