//��ͨԱ���ļ�
#pragma once
#include<iostream>
#include<string>
#include"worker.h"	//�̳У���Ҫ��������ͷ�ļ�
using namespace std;

class Employee :public Worker	//��ͨԱ���࣬�̳��Գ���ְ�����࣬����д�����д��麯��
{
public:
	Employee(int id, string name, int dId);	//�вι��캯������������ְ����ţ����������ű�ţ�

	void showInfo();	//��ʾ������Ϣ

	string getDeptName();	//��ȡ��λ��Ϣ
};
