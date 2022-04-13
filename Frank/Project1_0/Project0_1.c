//注释(不被编译器识别)两种形式如下
/*1 My First C Program*/
//2 My First C Program

#include <stdio.h>
//#include (包含) 
//<stdio.h>(.head头文件,stdio中std表示standard,io表示input out)
//#include <stdio.h>即这个文件可能会包含一个输入输出的头文件
int main(void)
{
	printf("Hello,World\n");
	//print 打印,f格式化,printf表示格式化输出,\n表示回车换行
	return 0;
}
