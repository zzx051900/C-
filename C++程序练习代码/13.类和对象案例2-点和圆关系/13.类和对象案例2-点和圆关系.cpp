#include<iostream>
#include"point.h"
#include"circle.h"

using namespace std;

//函数声明
void isInCircle(Circle &c, Point &p);

int main()
{
	Circle c;//创建一个圆
	c.setR(10);//设置圆的半径
	Point center;//创建圆的圆心
	center.setX(10);//设置圆心的x
	center.setY(0);//设置圆心的y
	c.setCenter(center);//设置圆心
	Point p;//创建点
	p.setX(10);//设置点的x
	p.setY(5);//设置点的y
	//p.setY(10);
	//p.setY(15);

	isInCircle(c, p);

	system("pause");
	return 0;
}

//判断点和圆的关系
void isInCircle(Circle &c, Point &p)
{
	//计算两点间距离的平方
	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) +
		(c.getCenter().getY() - p.getY())*(c.getCenter().getY() - p.getY());
	//计算半径的平方
	int rDistance = c.getR() * c.getR();
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}
