//25.有关sizeof的进一步理解
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int i = 0;//全局变量和静态变量默认初始化为0，局部变量默认初始化为随机值

int main()
{
	i--;//-1
	if (i>sizeof(-1))//sizeof的返回值为无符号整型，-1参与运算时也会转化为无符号整型
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}