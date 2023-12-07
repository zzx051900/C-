//经理文件
#pragma once
#include<iostream>
#include<string>
#include"worker.h"	
using namespace std;

class Manager :public Worker	//经理类，继承自抽象职工基类，并重写父类中纯虚函数
{
public:
	Manager(int id, string name, int dId);	//有参构造函数声明（传入职工编号，姓名，部门编号）

	void showInfo();	//显示个人信息

	string getDeptName();	//获取岗位信息
};