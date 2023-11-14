//8.判断素数（改进）
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			return 0;
		}
	}

	return 1;

}
int main()
{
	int m = 0;
	scanf("%d", &m);
	//是素数返回1，不是素数返回0
	printf("%d\n", is_prime(m));
	return 0;
}