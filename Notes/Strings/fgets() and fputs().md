#  fgets() and fputs()

## 1.`gets()`和`puts()`

> 这两个函数仅做了解，详细用法见https://www.runoob.com/cprogramming/c-function-gets.html 和 https://www.runoob.com/cprogramming/c-function-puts.html 鼓励使用下面介绍的`fgets()`和`fputs()`。

C 库函数`char *gets(char *str) `从标准输入 stdin 读取一行，并把它存储在 str 所指向的字符串中。当读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。

C 库函数` int puts(const char *str)`把一个字符串写入到标准输出 stdout，直到空字符，但不包括空字符。换行符会被追加到输出中。

库函数gets()和puts()仅有一个参数，字符串容易溢出。因此C99建议不要再使用它，而C11直接从标准库中废除了这个函数。但考虑到要兼容以前的代码，大部分编译器继续支持这两个函数。

## 2.`fgets()`

### 描述
C 库函数` char *fgets(char *str, int n, FILE *stream) `从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取 (n-1) 个字符时，==或者读取到换行符时(会将他存储在字符串中)==，或者到达文件末尾时，它会停止，具体视情况而定。

### 声明
下面是` fgets() `函数的声明。

```c
char *fgets(char *str, int n, FILE *stream)
```

### 参数
`str` 是指向一个**字符数组**的指针，该数组存储了要读取的字符串。
`n` 是要读取的最大字符数（包括最后的空字符）。通常是使用以` str `传递的数组长度。
`stream` 是指向 FILE 对象的指针，该`FILE `对象标识了要从中读取字符的流。==如果要从键盘输入数据，则以`stdin`（标准输入）作为参数。==

### 返回值
如果成功，该函数返回相同的` str `参数。如果到达文件末尾或者没有读取到任何字符，`str `的内容保持不变，并返回一个空指针。

如果发生错误，返回一个空指针。

### 实例

```c
/*  fgets1.c  -- using fgets() and fputs() */
#include <stdio.h>
#define STLEN 14
int main(void)
{
    char words[STLEN];
    
    puts("Enter a string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Enter another string, please.");
    fgets(words, STLEN, stdin);
    printf("Your string twice (puts(), then fputs()):\n");
    puts(words);
    fputs(words, stdout);
    puts("Done.");
    
    return 0;
}
```
输出：
```
Enter a string, please.
apple pie
Your string twice (puts(), then fputs()):
apple pie

apple pie
Enter another string, please.
strawberry shortcake
Your string twice (puts(), then fputs()):
strawberry sh
strawberry shDone.
```
`apple pie`没有超过大小限制，`puts()`显示字符串时在结尾添加换行符，因此有一行空行，而==`fputs()`不在字符串结尾添加换行符==，所以未打印空行。

`strawberry shortcake`超越了大小限制，所以`fputs()`只读取了13个字符`strawberry sh\0`存储在数组中。

## 3.`fputs()`

**描述**
C 库函数 `int fputs(const char *str, FILE *stream) `把字符串写入到指定的流 `stream` 中，但不包括空字符。

**声明**
下面是 `fputs() `函数的声明。
```
int fputs(const char *str, FILE *stream)
```
**参数**
`str`是一个数组，包含了要写入的以空字符终止的字符序列。
`stream ` 这是指向 FILE 对象的指针，该 `FILE` 对象标识了要被写入字符串的流。如果要打印在显示器上，则以`stdout`作为输出。
**返回值**
该函数返回一个非负值，如果发生错误则返回`EOF`。

实例
下面的实例演示了` fputs() `函数的用法。
```c

#include <stdio.h>

int main ()
{
   FILE *fp;

   fp = fopen("file.txt", "w+");

   fputs("这是 C 语言。", fp);
   fputs("这是一种系统程序设计语言。", fp);

   fclose(fp);
   
   return(0);
}
```
让我们编译并运行上面的程序，这将创建文件` file.txt`，它的内容如下：
```
这是 C 语言。这是一种系统程序设计语言。
```
现在让我们使用下面的程序查看上面文件的内容：
```

#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   while(1)
   {
      c = fgetc(fp);
      if( feof(fp) )
      {
          break ;
      }
      printf("%c", c);
   }
   fclose(fp);
   return(0);
}
```
##4.`printf()`

`printf()`函数的形式比较复杂，计算时间更长，但是它更多才多艺，因为他可以格式化不同的数据类型。

同时，当打印多个字符串时，`printf()`更加简单。

注意：与`puts()`不同，`printf()`并不会自动在每个字符串末尾加上一个换行符。因此，必须在参数中指明在哪里使用换行符。