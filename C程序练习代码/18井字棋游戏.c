//18.测试井字棋游戏（宏定义在函数中使用时未进行参数传递）

//可更改棋盘大小，但局势判断环节只会判断井字棋
//电脑方只会进行最简单的随机落子

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3//棋盘行数
#define COL 3//棋盘列数
//行和列已经预定义好了，函数中使用时还需要传参吗？？

//函数声明
void menu();
void test();
void game();
void Displayboard(char board[ROW][COL]);
void Initboard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);
int Full(char board[ROW][COL]);

void menu()//提示菜单
{
	printf("***********************\n");
	printf("*** 1.game  0.exit ****\n");
	printf("***********************\n");
}

void test()//选择是否进入游戏或再次进入游戏
{
	int input = 0;
	do
	{
		menu();//输出提示菜单
		printf("请选择是否开始游戏：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏函数，包含整个游戏流程
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input);//只有输入零会停止
}

void game()//游戏的整个实现流程
{
	char flag = '0';//用于表示游戏状态
	//'*'表示玩家赢，'#'表示电脑赢，'Q‘表示平局，'C’表示继续
	char board[ROW][COL] = { 0 }; //数组，存放棋盘信息//使用预定义ROW和COL方便后续修改棋盘行列大小
	Initboard(board);//棋盘初始化
	Displayboard(board);//打印数组(传参的时候传的是数组名，实参行，实参列）
	//正式下棋
	while (1)
	{
		//玩家走
		PlayerMove(board);
		Displayboard(board);
		flag = IsWin(board);//判断输赢
		if (flag != 'C')//如果判断条件已经不为'C'，则直接跳出
		{
			break;
		}
		//电脑走
		ComputerMove(board);
		Displayboard(board);
		flag = IsWin(board);//判断输赢
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("玩家赢\n\n");
	}
	else if (flag == '#')
	{
		printf("电脑赢\n\n");
	}
	else if (flag == 'Q')
	{
		printf("平局\n\n");
	}
}

//理想棋盘状态
// a | a | a
//---|---|---
// a | a | a
//---|---|---
// a | a | a

void Initboard(char board[ROW][COL])//棋盘数组初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COL; j++)
		{
			board[i][j] = ' ';//初始给每个元素一个空格
		}
	}
}

void Displayboard(char board[ROW][COL])//打印棋盘,参数为一个3×3的棋盘，一个形参行，一个形参列
{
	for (int i = 0; i<ROW; i++)//外层循环，循环行,
	{
		//打印一行的数据
		for (int j = 0; j<COL - 1; j++)//内层循环，循环列，前COL－1组元素
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c \n", board[i][COL - 1]);//每一列最后一个元素
		//打印分割行(第ROW-1行不需要分割行）
		if (i<ROW - 1)
		{
			for (int j = 0; j<COL - 1; j++)//内层循环，循环列，前COL－1组元素
			{
				printf("---|");
			}
			printf("---\n");//分割行的每一列最后一组元素
		}
	}
}

void PlayerMove(char board[ROW][COL])//玩家落子
{
	int i = 0;
	int j = 0;
	printf("玩家走:>\n");
	while (1)//循环判断，直到玩家输入正确
	{
		printf("玩家请落子\n");
		scanf("%d %d", &i, &j);//玩家输入落子的坐标//默认玩家认为坐标从（1，1）开始
		if (i >= 1 && i <= ROW&&j >= 1 && j <= COL&&board[i - 1][j - 1] == ' ')//这个位置是空格，代表可以落子
		{
			board[i - 1][j - 1] = '*';//玩家落子用*表示
			break;
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])//电脑落子，为随机生成
{
	int i = 0;
	int j = 0;
	printf("电脑走:>\n");
	while (1)//循环判断，直到电脑随机数输入正确
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' ')//电脑落子生成的下标就是数组下标，不用更改
		{
			board[i][j] = '#';//电脑落子用#表示
			break;
		}
	}
}

int Full(char board[ROW][COL])//判断棋盘是否已满
{
	for (int i = 0; i<ROW; i++)
	{
		for (int j = 0; j<COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL])//判断局势
{
	for (int i = 0; i<ROW; i++)//判断列是否三个相连
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int j = 0; j<COL; j++)//判断行是否三个相连
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//判断对角线是否三个相连
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//若仍不满足
	if (Full(board) == 1)//棋盘已满，且仍为跳出说明平局
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}

int main()
{
	srand((unsigned int)time(NULL));//初始化随机数发生器
	test();///开始测试
	return 0;
}
