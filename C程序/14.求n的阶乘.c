//14.求n的阶乘
//（分别用循环和递归实现）

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Fac1(int n)//用循环的方法求阶乘
{
	int ret = 1;
	for (int i = 1; i <= n; i++)
	{
		ret *= i;
	}
	return ret;
}

int Fac2(int n)//用递归的方法求阶乘
{
	if (n == 1)//可以是等于，注意"等于"是"==”，一个"=”表示赋值！！！
		return 1;
	return n*Fac2(n - 1);

}

int main()
{
	int n = 0;//n的阶乘
	int ret = 0;//存放结果
	scanf("%d", &n);
	ret = Fac1(n);
	printf("%d\n", ret);
	ret = Fac2(n);
	printf("%d\n", ret);
	return 0;
}