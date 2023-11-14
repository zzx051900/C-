//11.初体验递归
//接受一个无符号整型，按顺序打印他的每一位(使用递归）
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void print(int num)
{
	if (num>9)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}

int main()
{

	int num = 0;
	scanf("%d", &num);
	print(num);
	return 0;
}