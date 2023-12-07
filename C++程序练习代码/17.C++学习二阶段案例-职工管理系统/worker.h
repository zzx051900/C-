#pragma once
#include<iostream>
#include<string>
using namespace std;

class Worker		//抽象职工基类	抽象类不做实现不实例化，所以也不需要cpp文件
{
public:
	//职工行为
	virtual void showInfo() = 0;		//展示个人信息（纯虚函数）
	virtual string getDeptName() = 0;	//获取岗位信息（纯虚函数）

	//职工属性
	int m_Id;	//职工编号
	string m_Name;	//职工姓名
	int m_DeptId;	//职工所在部门名称编号
};
