//普通员工文件
#pragma once
#include<iostream>
#include<string>
#include"worker.h"	//继承，需要包含父类头文件
using namespace std;

class Employee :public Worker	//普通员工类，继承自抽象职工基类，并重写父类中纯虚函数
{
public:
	Employee(int id, string name, int dId);	//有参构造函数声明（传入职工编号，姓名，部门编号）

	void showInfo();	//显示个人信息

	string getDeptName();	//获取岗位信息
};
