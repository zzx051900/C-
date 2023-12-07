#include"manager.h"

Manager::Manager(int id, string name, int dId)	//有参构造函数声明（传入职工编号，姓名，部门编号）
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo()	//显示个人信息
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()	//获取岗位信息
		<< "\t岗位职责：完成老板交给的任务，并且下发任务给普通员工" << endl;
}

string Manager::getDeptName()	//获取岗位信息
{
	return string("经理");
}