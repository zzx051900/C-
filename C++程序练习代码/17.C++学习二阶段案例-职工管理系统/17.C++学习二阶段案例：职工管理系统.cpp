#include<iostream>
#include<string>
#include"workerManager.h"	//职工管理文件
#include"worker.h"	//抽象职工基类文件
#include"employee.h"	//普通员工文件
#include"manager.h"	//经理文件
#include"boss.h"	//老板文件
using namespace std;

void test01(WorkerManager &wm);

int main()
{
	WorkerManager wm;	//实例化管理者对象
	test01(wm);
	
	system("pause");
	return 0;
}

//执行函数
void test01(WorkerManager &wm)
{
	int choice = 0;
	while (1)
	{
		wm.Show_Menu();	//调用展示菜单
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();	//退出系统
			break;
		case 1:
			wm.Add_Emp();	//添加职工
			break;
		case 2:
			wm.Show_Emp();	//显示职工
			break;
		case 3:
			wm.Del_Emp();	//删除职工
			break;
		case 4:
			wm.Mod_Emp();	//修改职工
			break;
		case 5:
			wm.Find_Emp();	//查找职工
			break;
		case 6:
			wm.Sort_Emp();	//排序职工
			break;
		case 7:
			wm.Clean_File();//清空文件
			break;
		default:
			system("cls");	//清空屏幕
			break;
		}
	}
}