//18.���Ծ�������Ϸ���궨���ں�����ʹ��ʱδ���в������ݣ�

//�ɸ������̴�С���������жϻ���ֻ���жϾ�����
//���Է�ֻ�������򵥵��������

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3//��������
#define COL 3//��������
//�к����Ѿ�Ԥ������ˣ�������ʹ��ʱ����Ҫ�����𣿣�

//��������
void menu();
void test();
void game();
void Displayboard(char board[ROW][COL]);
void Initboard(char board[ROW][COL]);
void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);
char IsWin(char board[ROW][COL]);
int Full(char board[ROW][COL]);

void menu()//��ʾ�˵�
{
	printf("***********************\n");
	printf("*** 1.game  0.exit ****\n");
	printf("***********************\n");
}

void test()//ѡ���Ƿ������Ϸ���ٴν�����Ϸ
{
	int input = 0;
	do
	{
		menu();//�����ʾ�˵�
		printf("��ѡ���Ƿ�ʼ��Ϸ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸ����������������Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);//ֻ���������ֹͣ
}

void game()//��Ϸ������ʵ������
{
	char flag = '0';//���ڱ�ʾ��Ϸ״̬
	//'*'��ʾ���Ӯ��'#'��ʾ����Ӯ��'Q����ʾƽ�֣�'C����ʾ����
	char board[ROW][COL] = { 0 }; //���飬���������Ϣ//ʹ��Ԥ����ROW��COL��������޸��������д�С
	Initboard(board);//���̳�ʼ��
	Displayboard(board);//��ӡ����(���ε�ʱ�򴫵�����������ʵ���У�ʵ���У�
	//��ʽ����
	while (1)
	{
		//�����
		PlayerMove(board);
		Displayboard(board);
		flag = IsWin(board);//�ж���Ӯ
		if (flag != 'C')//����ж������Ѿ���Ϊ'C'����ֱ������
		{
			break;
		}
		//������
		ComputerMove(board);
		Displayboard(board);
		flag = IsWin(board);//�ж���Ӯ
		if (flag != 'C')
		{
			break;
		}
	}
	if (flag == '*')
	{
		printf("���Ӯ\n\n");
	}
	else if (flag == '#')
	{
		printf("����Ӯ\n\n");
	}
	else if (flag == 'Q')
	{
		printf("ƽ��\n\n");
	}
}

//��������״̬
// a | a | a
//---|---|---
// a | a | a
//---|---|---
// a | a | a

void Initboard(char board[ROW][COL])//���������ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i<ROW; i++)
	{
		for (j = 0; j<COL; j++)
		{
			board[i][j] = ' ';//��ʼ��ÿ��Ԫ��һ���ո�
		}
	}
}

void Displayboard(char board[ROW][COL])//��ӡ����,����Ϊһ��3��3�����̣�һ���β��У�һ���β���
{
	for (int i = 0; i<ROW; i++)//���ѭ����ѭ����,
	{
		//��ӡһ�е�����
		for (int j = 0; j<COL - 1; j++)//�ڲ�ѭ����ѭ���У�ǰCOL��1��Ԫ��
		{
			printf(" %c |", board[i][j]);
		}
		printf(" %c \n", board[i][COL - 1]);//ÿһ�����һ��Ԫ��
		//��ӡ�ָ���(��ROW-1�в���Ҫ�ָ��У�
		if (i<ROW - 1)
		{
			for (int j = 0; j<COL - 1; j++)//�ڲ�ѭ����ѭ���У�ǰCOL��1��Ԫ��
			{
				printf("---|");
			}
			printf("---\n");//�ָ��е�ÿһ�����һ��Ԫ��
		}
	}
}

void PlayerMove(char board[ROW][COL])//�������
{
	int i = 0;
	int j = 0;
	printf("�����:>\n");
	while (1)//ѭ���жϣ�ֱ�����������ȷ
	{
		printf("���������\n");
		scanf("%d %d", &i, &j);//����������ӵ�����//Ĭ�������Ϊ����ӣ�1��1����ʼ
		if (i >= 1 && i <= ROW&&j >= 1 && j <= COL&&board[i - 1][j - 1] == ' ')//���λ���ǿո񣬴����������
		{
			board[i - 1][j - 1] = '*';//���������*��ʾ
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])//�������ӣ�Ϊ�������
{
	int i = 0;
	int j = 0;
	printf("������:>\n");
	while (1)//ѭ���жϣ�ֱ�����������������ȷ
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' ')//�����������ɵ��±���������±꣬���ø���
		{
			board[i][j] = '#';//����������#��ʾ
			break;
		}
	}
}

int Full(char board[ROW][COL])//�ж������Ƿ�����
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

char IsWin(char board[ROW][COL])//�жϾ���
{
	for (int i = 0; i<ROW; i++)//�ж����Ƿ���������
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int j = 0; j<COL; j++)//�ж����Ƿ���������
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	//�ж϶Խ����Ƿ���������
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[0][0];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[0][2];
	//���Բ�����
	if (Full(board) == 1)//��������������Ϊ����˵��ƽ��
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
	srand((unsigned int)time(NULL));//��ʼ�������������
	test();///��ʼ����
	return 0;
}
