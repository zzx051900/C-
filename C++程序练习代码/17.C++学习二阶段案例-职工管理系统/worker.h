#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker		//����ְ������	�����಻��ʵ�ֲ�ʵ����������Ҳ����Ҫcpp�ļ�
{
public:
	//ְ����Ϊ
	virtual void showInfo() = 0;		//չʾ������Ϣ�����麯����
	virtual string getDeptName() = 0;	//��ȡ��λ��Ϣ�����麯����

	//ְ������
	int m_Id;	//ְ�����
	string m_Name;	//ְ������
	int m_DeptId;	//ְ�����ڲ������Ʊ��
};
