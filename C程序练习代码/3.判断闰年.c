//3.判断闰年
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	//闰年标准：1.能被4整除且不能被100整除 2.能被400整除
	if (((n % 4 == 0) && (n % 100 != 0)) || (n % 400 == 0))
	{
		printf("%d是闰年\n", n);
	}
	else
	{
		printf("%d不是闰年\n", n);
	}
	return 0;
}