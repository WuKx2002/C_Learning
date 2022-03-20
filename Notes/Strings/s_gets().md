# s_gets()

我们知道，`fgets()`函数在读取字符串时会存储换行符，这有好处也有坏处。

- 好处：检查换行符可以判断是否读取了一整行，如果不是，要妥善处理剩下的字符。
- 坏处：我们可能不想把换行符存储在字符串中，这样可能会带来一些麻烦。

如何处理掉换行符？

我们可以查找换行符，找到后替换成空字符。

```c
while (word[i] != '\n')
{
	i++;
}
word[i] = '\0';
```

如何处理仍然留在输入行中的字符串？

如果目标数组装不下一整行输入，我们就丢弃多出的字符。

```c
while (getchar() != '\n')
{
	continue;//读取，但不存储。
}
```
实例：
```c
#include <stdio.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    int i;
    
    puts("Enter strings (empty line to quit):");
    while (fgets(words, STLEN, stdin) != NULL
                          && words[0] != '\n')
    {
        i = 0;
        while (words[i] != '\n' && words[i] != '\0')
        {
        	i++;
        }
        if (words[i] == '\n')
        {
        	words[i] = '\0';
        }
        else 
        {
        	 while (getchar() != '\n')
                continue;
        }
        puts(words);        
    }
    puts("done");
    return 0;
}
```

这个程序演示了`fgets()`函数读取整行输入并用空字符替代换行符，或者读取一部分输入，并丢弃剩余部分。既然C标准库中没有这种函数，那么我们自己创建一个。

```c
char * s_gets(char * st, int n)
{
    char * ret_val;
    char i = 0;
    
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

