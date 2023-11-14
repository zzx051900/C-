//26.求二进制中1的个数(负数用补码表示)

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int Count1(int a)
{
	int count = 0;
	for (int i = 0; i<32; i++)
	{
		if ((a >> i) & 1 == 1)//按位与1，ke判断最后一个是否是1
			count++;
	}
	return count;
}

int Count2(int a)
{
	int count = 0;
	while (a)
	{
		a = a&(a - 1);//使a的二进制形式的最右边一个数变成0
		count++;
	}
	return count;
}

int main()
{
	int a = 0, count = 0;
	scanf("%d", &a);
	count = Count1(a);
	printf("%d\n", count);
	count = Count2(a);
	printf("%d\n", count);
	return 0;
}