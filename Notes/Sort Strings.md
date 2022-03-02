# Sort Strings

> ## 选择排序算法
>
> **1.算法步骤**
>
> - 首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
>
> - 再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
>
> - 重复第二步，直到所有元素均排序完毕。
>
> ![](https://markdown-1309501826.cos.ap-nanjing.myqcloud.com/Typora/C语言/选择排序算法动图.gif)
>
> **2.代码实现**
>
> ```c
> void swap(int *a,int *b) 
> {
>     int temp = *a;
>     *a = *b;
>     *b = temp;
> }
> void selection_sort(int arr[], int len)
> {
>     int i,j;
> 
>     for (i = 0 ; i < len - 1 ; i++)
>     {
>         int min = i;
>         for (j = i + 1; j < len; j++)
>         {  
>             if (arr[j] < arr[min])
>             {   
>                 min = j;
>             }
>         }
>         swap(&arr[min], &arr[i]);
>     }
> }
> ```
> C标准库`<stdlib.h>`中有一个更高级的排序函数`qsort()`，该函数使用一个指向函数的指针进行排序比较，以后再引入。

下面这个程序，实现了按字符串的首字母对字符串进行排序：

```c
#include <stdio.h>
#include <string.h>
#define SIZE 81        					//限制字符长度，包括\0
#define LIM 20         					//可读入的最多行数
#define HALT ""        					//空字符串停止输入
void stsrt(char *strings[], int num);	//字符串排序函数  
char * s_gets(char * st, int n);

int main(void)
{
    char input[LIM][SIZE];              //存储输入的数组
    char *ptstr[LIM];                   //内含指针变量的数组
    int ct = 0;                         //输入计数
    int k;                              //输出计数         
    
    printf("Input up to %d lines, and I will sort them.\n",LIM);
    printf("To stop, press the Enter key at a line's start.\n");
    while (ct < LIM && s_gets(input[ct], SIZE) != NULL
           && input[ct][0] != '\0')
    {
        ptstr[ct] = input[ct];          //设置指针指向字符串
        ct++;
    }
    stsrt(ptstr, ct);                   //字符串排序函数        
    puts("\nHere's the sorted list:\n");
    for (k = 0; k < ct; k++)
    {
        puts(ptstr[k]) ;
    }                                   //排序后的指针       
    
    return 0;
}

//字符串-指针-排序函数（选择排序算法）
void stsrt(char *strings[], int num)
{
    char *temp;
    int top, seek;
    
    for (top = 0; top < num-1; top++)
    {
        for (seek = top + 1; seek < num; seek++)
        {
            if (strcmp(strings[top],strings[seek]) > 0)
                //如果第一个字符串在第二个字符串后面，strcmp()返回正数
            {
                temp = strings[top];
                strings[top] = strings[seek];
                strings[seek] = temp;
            }
        }
            
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
        {
			i++;
        }
        if(st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {
            while (getchar() != '\n')
                continue; 
        }
  
    }
    return ret_val;
}
```

