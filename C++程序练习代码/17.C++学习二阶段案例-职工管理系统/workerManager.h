#pragma once		//��ֹͷ�ļ��ظ�����
#include<iostream>
#include<fstream>
#include"worker.h"	//��Ҫ��������ְ�������ļ�
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
//��Ա������
	WorkerManager();	//���죬ͷ�ļ�ֻ��������ʵ��

	void Show_Menu();	//չʾ�˵�

	void Add_Emp();		//���ְ��

	int get_EmpNum();	//��ȡ�ļ��е�ְ������

	void init_Emp();	//��ʼ��ְ������

	void Show_Emp();	//����µĳ�Ա����

	int IsExist(int id);	//�ж�ְ���Ƿ����

	void Del_Emp();	//ɾ��ְ��

	void Mod_Emp();	//�޸�ְ��

	void Find_Emp();	//����ְ��

	void Sort_Emp();	//����

	void save();	//�����ļ�

	void Clean_File();	//����ļ�

	void exitSystem();	//�˳�ϵͳ

	~WorkerManager();	//������ͷ�ļ�ֻ��������ʵ��
//��Ա���ԣ�
	int m_EmpNum;	//��¼�ļ��е���������
	Worker** m_EmpArray;	//ְ�������ָ��		
	bool m_FileIsEmpty;	//��־�ļ��Ƿ�Ϊ��
};