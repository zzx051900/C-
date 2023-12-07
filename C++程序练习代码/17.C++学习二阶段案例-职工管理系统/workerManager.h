#pragma once		//防止头文件重复包含
#include<iostream>
#include<fstream>
#include"worker.h"	//需要包含抽象职工基类文件
#include"employee.h"
#include"manager.h"
#include"boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
//成员函数：
	WorkerManager();	//构造，头文件只声明，不实现

	void Show_Menu();	//展示菜单

	void Add_Emp();		//添加职工

	int get_EmpNum();	//获取文件中的职工人数

	void init_Emp();	//初始化职工数组

	void Show_Emp();	//添加新的成员函数

	int IsExist(int id);	//判断职工是否存在

	void Del_Emp();	//删除职工

	void Mod_Emp();	//修改职工

	void Find_Emp();	//查找职工

	void Sort_Emp();	//排序

	void save();	//保存文件

	void Clean_File();	//清空文件

	void exitSystem();	//退出系统

	~WorkerManager();	//析构，头文件只声明，不实现
//成员属性：
	int m_EmpNum;	//记录文件中的人数个数
	Worker** m_EmpArray;	//职工数组的指针		
	bool m_FileIsEmpty;	//标志文件是否为空
};