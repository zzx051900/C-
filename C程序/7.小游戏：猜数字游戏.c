//7.小游戏：猜数字游戏
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("***************************\n");
	printf("****  1.play   0.exit *****\n");
	printf("***************************\n");
}

void game()
{
	int ret = rand() % 100 + 1;//生成1~100的随机数
	int guess = 0;//接收玩家猜的输入的数字
	while (1)//死循环不断判断，直到猜到为止，使用break跳出
	{
		printf("请猜数字:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("猜小了\n");
		}
		else if (guess > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，猜对了！\n");
			break;
		}

	}
}

void judge()//玩家选择是否开始游戏
{
	int input = 0;//玩家输入1或0，选择是否开始游戏
	do//因为程序最少执行一次，所以选择do.while结构
	{
		menu();//提示窗口
		printf("开始游戏或继续游戏请输入1，退出游戏请输入0>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//猜数字游戏函数
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);//输入0时退出，输入1或其他值时都可再次选择
}
int main()
{
	srand((unsigned)time(NULL));//初始化随机数发生器
	judge();//玩家选择是否开始游戏
	return 0;
}