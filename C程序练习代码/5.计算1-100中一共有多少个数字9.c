//5.计算1到100中一共含多少个数字9
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int i = 0, count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)//余数为9
			count++;
		if (i / 10 == 9)//十位数为9
			count++;
	}
	printf("%d\n", count);
	return 0;
}
