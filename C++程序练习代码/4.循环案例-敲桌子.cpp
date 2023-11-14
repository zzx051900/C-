/*
案例描述：
从1开始数到数字100，如果数字中含有7，或该数字是7的倍数，
我们打印敲桌子，其余数字直接打印输出
*/
#include<iostream>

using namespace std;

int main()
{

	for (int i = 1; i <= 100; i++)
	{
		//个位是7（i % 10 == 7）    
		//十位是7（i / 10 == 7）
		//7的倍数（i % 7 == 0）
		if (i % 10 == 7 || i / 10 == 7 || i % 7 == 0)
		{
			cout << i << " 敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}
	}
	system("pause");
	return 0;
}