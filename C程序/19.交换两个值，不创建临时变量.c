//19.交换两个值，不创建临时变量

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	//交换a和b的值
	int a = 5;
	int b = 3;
	printf("a=%d b=%d\n", a, b);
	//方案一：创建临时变量
	int tmp = a;
	a = b;
	b = tmp;
	printf("a=%d b=%d\n", a, b);

	//方案二：加减法（可能产生溢出）
	a = a + b;//8,3
	b = a - b;//8,5
	a = a - b;//3,5
	printf("a=%d b=%d\n", a, b);

	//方案三：易或法（不会产生溢出）
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d b=%d\n", a, b);
	return 0;
}