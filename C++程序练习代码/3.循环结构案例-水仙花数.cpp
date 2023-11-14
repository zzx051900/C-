/*
案例描述：水仙花数是指一个3位数，它的每个位上的数字的3次幂之和等于它本身
例如：1^3+5^3+3^3=153
使用do...while语句，求出所有3位数中的水仙花数
*/
#include<iostream>

using namespace std;

int main()
{
	int m = 100;//3位数，从100开始

	int a = 0;//获取百位数字
	int b = 0;//获取十位数字
	int c = 0;//获取个位数字

	do
	{
		a = m / 100;
		b = m / 10 % 10;
		c = m % 10;
		if (a*a*a + b*b*b + c*c*c == m)
		{
			cout << m << endl;
		}
		m++;
	} while (m < 1000);

	system("pause");
	return 0;
}