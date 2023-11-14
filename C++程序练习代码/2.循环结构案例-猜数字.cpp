#include<iostream>
#include<ctime>//time系统时间的头文件
using namespace std;

int main()
{
	//添加随机数种子，利用当前系统时间生成随机数，防止每次随机数都一样
	srand((unsigned int)time(NULL));

	//系统生成随机数(伪随机数）
	int num = rand() % 100 + 1;//rand()%100，生成0~99的随机数
	//cout << num << endl;

	int val = 0;

	while (1)
	{
		//玩家进行猜测
		cin >> val;

		//判断玩家猜测
		if (val > num)
		{
			cout << "猜测过大" << endl;
		}
		else if (val < num)
		{
			cout << "猜测过小" << endl;
		}
		else
		{
			cout << "恭喜您猜对了" << endl;
			break;
		}
	}

	system("pause");
	return 0;
}