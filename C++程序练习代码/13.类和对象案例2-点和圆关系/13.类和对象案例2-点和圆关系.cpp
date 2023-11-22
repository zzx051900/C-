#include<iostream>
#include"point.h"
#include"circle.h"

using namespace std;

//��������
void isInCircle(Circle &c, Point &p);

int main()
{
	Circle c;//����һ��Բ
	c.setR(10);//����Բ�İ뾶
	Point center;//����Բ��Բ��
	center.setX(10);//����Բ�ĵ�x
	center.setY(0);//����Բ�ĵ�y
	c.setCenter(center);//����Բ��
	Point p;//������
	p.setX(10);//���õ��x
	p.setY(5);//���õ��y
	//p.setY(10);
	//p.setY(15);

	isInCircle(c, p);

	system("pause");
	return 0;
}

//�жϵ��Բ�Ĺ�ϵ
void isInCircle(Circle &c, Point &p)
{
	//�������������ƽ��
	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());
	//����뾶��ƽ��
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}
