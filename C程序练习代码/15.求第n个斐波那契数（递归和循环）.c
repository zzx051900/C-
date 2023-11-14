//15.求第n个斐波那契数（递归和循环）
//（但递归同一个数会被大量重复计算，浪费资源）
//递归和循环各适用于不用场景，并不是哪一种就一定永远是好的方法

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Fib1(int n)//递归
{
	if (n <= 2)
		return 1;
	if (n>2)
		return Fib1(n - 1) + Fib1(n - 2);
}

int Fib2(int n)//循环，可以避免大量重复
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n>2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;//求第n个斐波那契数
	int ret = 0;
	scanf("%d", &n);
	ret = Fib1(n);
	printf("%d\n", ret);
	ret = Fib2(n);
	printf("%d\n", ret);
	for (int i = 1; i <= 10; i++)///输出第1~10个斐波那契数
	{
		printf("%d\t", Fib1(i));
	}

	return 0;
}