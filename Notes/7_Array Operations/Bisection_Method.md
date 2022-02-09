# Bisection_Method

> 二分查找

例如:在数组中搜索k=21

| `a[0]` | `a[1]` | `a[2]` | `a[3]` | `a[4]` | `a[5]` | `a[6]` | `a[7]` | `a[8]` | `a[9]` | `a[10]` |
| :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :-----: |
|   1    |   1    |   2    |   3    |   5    |   8    |   13   |   21   |   34   |   55   |   89    |

- `left = 0`,`right = 10`,`mid = (left + right) / 2 = 5`

| `a[left]` | `a[1]` | `a[2]` | `a[3]` | `a[4]` | `a[mid]` | `a[6]` | `a[7]` | `a[8]` | `a[9]` | `a[right]` |
| :-------: | :----: | :----: | :----: | :----: | :------: | :----: | :----: | :----: | :----: | :--------: |
|     1     |   1    |   2    |   3    |   5    |    8     |   13   |   21   |   34   |   55   |     89     |

- `a[mid] < k`

  那么

  ``left = mid + 1``

  ``mid = (left + right) / 2 = 8`

| `a[left]` | `a[7]` | `a[mid]` | `a[9]` | `a[right]` |
| :-------: | :----: | :------: | :----: | :--------: |
|    13     |   21   |    34    |   55   |     89     |

- `a[mid] > k`

  那么

  `right = mid - 1`

  `mid = (left + right) / 2 = 6`

| `a[left]` | `a[right]` |
| :-------: | :--------: |
|    13     |     21     |

- `a[mid] < k`

  那么

  `left = mid + 1`

  `mid = (left + right) / 2 = 7`

  则`a[left] = a [right] = a[mid] = 21`

> 二分搜索函数代码块:

```C
int search(int k, int a[], int len)
{
	int ret = -1;
	int left = 0;
	int right = len - 1;

	while(right > left)
	{
		int mid = (left + right) / 2;
		if (a[mid] = k) 
		{
			ret = mid;
			break;
		}else if (a[mid] > k) 
		{
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ret;
}
```

> **完整代码块**

```C
#include<stdio.h>

int search(int k, int a[], int len)
{
	int ret = -1;
	int left = 0;
	int right = len - 1;

	while(right > left)/*注意循环条件*/
	{
		int mid = (left + right) / 2;
		if (a[mid] = k) 
		{
			ret = mid;
			break;
		}else if (a[mid] > k) 
		{
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ret;/*单一出口*/
}

int main(void)
{
	int a[] = { 1,1,2,3,5,8,13,21,34,55,89 };
	int len = sizeof(a) / sizeof(a[0]);
	int k;
	printf("请输入要查找的数:");
	scanf_s("%d",&k);

	int ret = search(k, a, len);/*调用函数的方法*/
	if (ret == -1)
	{
		printf("未找到");
	}
	else {
		printf("成功找到%d", k);
	}
	return 0;
}
```

