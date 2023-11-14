//28.获取一个数二进制形式的奇数位和偶数位并分别打印

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

void print(int m)//实现打印奇数位和偶数位
{
	printf("打印奇数位：\n");
	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
	printf("\n");

	printf("打印偶数位：\n");
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d", (m >> i) & 1);
	}
}

int main()
{
	int m = 0;
	scanf("%d", &m);
	print(m);
	return 0;
}