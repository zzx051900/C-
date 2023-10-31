//10.写一个函数，每一次调用函数就会让num的值加一
//（因为通过函数修改主程序中的值，所以要用传值调用）
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void Add(int* p)//用指针接收地址
{
	(*p)++;//  *用来解引用 ，++的优先级较高，要用括号括*p
}
int main()
{
	int num = 0;
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	Add(&num);//传的是num的地址
	printf("%d\n", num);//查看num的值是否改变
	return 0;
}