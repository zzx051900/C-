//�ϰ��ļ�
#pragma once
#include<iostream>
#include<string>
#include"worker.h"	
using namespace std;

class Boss :public Worker	//�ϰ��࣬�̳��Գ���ְ�����࣬����д�����д��麯��
{
public:
	Boss(int id, string name, int dId);	//�вι��캯������������ְ����ţ����������ű�ţ�

	void showInfo();	//��ʾ������Ϣ

	string getDeptName();	//��ȡ��λ��Ϣ
};