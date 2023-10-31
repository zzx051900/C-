//6.计算1/1-1/2+1/3-1/4+1/5...+1/99-1/100的值
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>
int main()
{
	int i = 1, flag = 1;//flag为负号标志
	double sum = 0;
	for (i = 1; i <= 100; i++)
	{
		flag = pow(-1, i + 1);//（方法2）符号为-1的i+1次方，用平方公式pow(a,b)
		sum += flag*(1.0 / i);//要得到浮点类型，则运算时至少一个数要为浮点类型，所以写1.0
		//flag = -flag;//(方法1）flag的负号每次刚好反转
	}
	printf("%lf\n", sum);
	return 0;
}