#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;

//

//��Ƶ���
class Point
{
public:
	//����x
	void setX(int x);

	//��ȡx
	int getX();

	//����y
	void setY(int y);

	//��ȡy
	int getY();


private:
	int m_X;//x����
	int m_Y;//y����
};