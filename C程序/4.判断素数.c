//4.判断是否为素数（试除法)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int n = 0, i = 2;			//n为要判断的素数，i为试除法需要的循环变量
	scanf("%d", &n);
	for (i; i < n; i++)		    //用n除以2到n-1的数，寻找是否有可以整除的数，没有则为素数(效率较低）//(优化）可以只判断到开平方n，用库函数sqrt()
	{
		if (n%i == 0)
			break;
	}
	if (i == n)
	{
		printf("%d为素数\n", n);
	}
	else
	{
		printf("%d不是素数\n", n);
	}
	return 0;
}