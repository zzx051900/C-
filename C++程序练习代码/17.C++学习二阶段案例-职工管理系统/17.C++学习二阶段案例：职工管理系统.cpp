#include<iostream>
#include<string>
#include"workerManager.h"	//ְ�������ļ�
#include"worker.h"	//����ְ�������ļ�
#include"employee.h"	//��ͨԱ���ļ�
#include"manager.h"	//�����ļ�
#include"boss.h"	//�ϰ��ļ�
using namespace std;

void test01(WorkerManager &wm);

int main()
{
	WorkerManager wm;	//ʵ���������߶���
	test01(wm);
	
	system("pause");
	return 0;
}

//ִ�к���
void test01(WorkerManager &wm)
{
	int choice = 0;
	while (1)
	{
		wm.Show_Menu();	//����չʾ�˵�
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();	//�˳�ϵͳ
			break;
		case 1:
			wm.Add_Emp();	//���ְ��
			break;
		case 2:
			wm.Show_Emp();	//��ʾְ��
			break;
		case 3:
			wm.Del_Emp();	//ɾ��ְ��
			break;
		case 4:
			wm.Mod_Emp();	//�޸�ְ��
			break;
		case 5:
			wm.Find_Emp();	//����ְ��
			break;
		case 6:
			wm.Sort_Emp();	//����ְ��
			break;
		case 7:
			wm.Clean_File();//����ļ�
			break;
		default:
			system("cls");	//�����Ļ
			break;
		}
	}
}