//30.有关数组元素访问越界的问题(不理解）--《C陷阱和缺陷》

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
int main()
{
	int i = 0;
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//vc6.0环境下 <=10,死循环
	//gcc编译器 <=10,死循环
	//vs2013 <=12,死循环

	//若后创建变量i，也不会死循环（不理解）
	for (i = 0; i <= 12; i++)
	{
		printf("hh\n");
		arr[i] = 0;
	}
	system("pause");
	return 0;
}
