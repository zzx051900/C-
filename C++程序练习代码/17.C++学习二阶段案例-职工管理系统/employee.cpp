#include"employee.h"

Employee::Employee(int id, string name, int dId)	//有参构造函数声明（传入职工编号，姓名，部门编号）
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
	//形参名与成员变量名一样时必须加this指针，不一样时可加可不加
}

void Employee::showInfo()	//显示个人信息
{
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()	//获取岗位信息
		<< "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName()	//获取岗位信息
{
	return string("员工");
}