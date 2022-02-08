//fathm_ft.c--把2英寻转换成英尺
#include <stdio.h>
int main(void)
{
	int feet, fathoms;
	/*与
	int feet；
	int fathoms;
	等价
	*/
	
	fathoms = 2;
	feet = 6 * fathoms;
	
	printf("There is %d feet in %d fothoms!\n", feet, fathoms);
	printf("Yes,I said %d feet!\n",6 * fathoms);

	return 0;
}