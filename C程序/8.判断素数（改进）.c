//8.�ж��������Ľ���
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
	//����������1��������������0
	printf("%d\n", is_prime(m));
	return 0;
}