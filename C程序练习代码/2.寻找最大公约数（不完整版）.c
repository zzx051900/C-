//2.寻找最大公约数（不完善版）

#include<stdio.h>

int main()
{
	int m = 0, n = 0, r = 0;
	scanf("%d %d", &m, &n);
	while (m%n)//辗转相除法，循环条件为取模不为零
	{
		r = m%n;
		m = n;
		n = r;
	}
	printf("%d\n", r);
	return 0;
}
