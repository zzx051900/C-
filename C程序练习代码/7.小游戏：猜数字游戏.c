//7.С��Ϸ����������Ϸ
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
	int ret = rand() % 100 + 1;//����1~100�������
	int guess = 0;//������Ҳµ����������
	while (1)//��ѭ�������жϣ�ֱ���µ�Ϊֹ��ʹ��break����
	{
		printf("�������:>");
		scanf("%d", &guess);
		if (guess < ret)
		{
			printf("��С��\n");
		}
		else if (guess > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬�¶��ˣ�\n");
			break;
		}

	}
}

void judge()//���ѡ���Ƿ�ʼ��Ϸ
{
	int input = 0;//�������1��0��ѡ���Ƿ�ʼ��Ϸ
	do//��Ϊ��������ִ��һ�Σ�����ѡ��do.while�ṹ
	{
		menu();//��ʾ����
		printf("��ʼ��Ϸ�������Ϸ������1���˳���Ϸ������0>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��������Ϸ����
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}

	} while (input);//����0ʱ�˳�������1������ֵʱ�����ٴ�ѡ��
}
int main()
{
	srand((unsigned)time(NULL));//��ʼ�������������
	judge();//���ѡ���Ƿ�ʼ��Ϸ
	return 0;
}