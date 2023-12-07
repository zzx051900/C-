#include"workerManager.h"

//构造函数，cpp文件中实现
WorkerManager::WorkerManager()	
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在的情况
	if (!ifs.is_open())	//如果文件打开失败，返回0，取反为1
	{
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;	//初始化人数为0
		this->m_FileIsEmpty = true;	//初始化文件为空标志
		this->m_EmpArray = NULL;	//初始化数组指针为空
		ifs.close();
		return;
	}

	//文件存在，但记录为空的情况
	char ch;
	ifs >> ch;	//读入文件中的一个字符，若文件为空，则读入的是EOF（？？？不太理解）
	if (ifs.eof())	//判断读入是否为EOF，若是，则为真
	{
		cout << "文件为空！" << endl;
		this->m_EmpNum = 0;	//初始化人数为0
		this->m_FileIsEmpty = true;	//初始化文件为空标志
		this->m_EmpArray = NULL;	//初始化数组指针为空
		ifs.close();
		return;
	}

	//文件存在，且记录数据
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;

	//初始化修改职工人数
	this->m_EmpNum = num;	

	//初始化修改职工数组
	this->m_EmpArray = new Worker*[this->m_EmpNum];	//该步骤应该是动态分配数组内存大小
	this->init_Emp(); //初始化职工数组（将文件中的职工信息放到堆区申请的职工数组中，便于程序执行）

	//初始化修改文件空标志为非空
	this->m_FileIsEmpty = false;

	/*
	//这里应该是测试
	//输出数组中职工信息，测试是否从文件中正确读取
	//这里也可以调用worker的三个子类的showInfo()函数，因为在初始化数组往worker**数组中创建新对象的时候就已经分类识别不同对象了，所有可以利用多态显示职工信息
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id
			<< "\t职工姓名：" << this->m_EmpArray[i]->m_Name
			<< "\t部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}*/
}

//菜单功能
void WorkerManager::Show_Menu()	
{
	cout << "**********************************" << endl;
	cout << "****** 欢迎使用职工管理系统 ******" << endl;
	cout << "********* 0.退出管理系统 *********"  << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "********* 3.删除离职职工 *********" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********* 6.按照编号排序 *********" << endl;
	cout << "********* 7.清空所有文档 *********" << endl;
	cout << "**********************************" << endl;
}

//添加职工
void WorkerManager::Add_Emp()		
{
	cout << "请输入添加职工的数量" << endl;
	int addNum;	//保存用户的输入数量
	cin >> addNum;
	//判断输入数据是否有效，大于零则有效，否则提示输入有误
	if (addNum > 0)
	{
		//添加思路是在堆区开辟一块新的数组内存空间，大小等于原职工数量加新添加的职工数量，将原数组内容移动到新数组，在后面继续添加新职工，添加完成后释放原数组空间，成员函数数组指针指向新的内存空间，更新职工数量
		int newSize = this->m_EmpNum + addNum;	//计算新空间的大小，等于原数量加新添加的数量
		Worker** newSpace = new Worker*[newSize];	//开辟新空间
		if (this->m_EmpArray != NULL)	//判断数组是否为空（？？？不理解），若不为空，则将原数组内容移动到新数组
		{
			for (int i = 0; i < this->m_EmpNum; i++)	//拷贝数组原有内容
			{
				newSpace[i] = this->m_EmpArray[i];	//（？？？）这样就可以拷贝吗
			}
		}
		for (int i = 0; i < addNum; i++)	//批量添加数据
		{
			int id;	//职工编号
			string name;	//姓名
			int dSelect;	//部门编号
			cout << "请输入第" << i + 1 << "个员工的职工编号:" << endl;
			cin >> id;
			cout << "请输入该员工的姓名:" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;	//新加入的这个职工在数组中的位置是this->m_EmpNum + i
		}
		delete[] this->m_EmpArray;	//释放原有数组
		this->m_EmpArray = newSpace;	//更改职工数组的指向，指向新建数组的首地址
		this->m_EmpNum = newSize;	//更新职工的数量
		this->m_FileIsEmpty = false;	//更新文件为非空状态
		cout << "成功添加" << addNum << "名新职工" << endl;
		this->save();	//添加成功后写入文件
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//获取文件中的职工人数
int WorkerManager::get_EmpNum()	
{
	ifstream ifs;	//创建读文件流
	ifs.open(FILENAME, ios::in);	//打开文件，为读文件打开

	int id;
	string name;
	int dId;

	int num = 0;	//统计人数

	while (ifs >> id && ifs >> name && ifs >> dId)	//成功读完一个人的数据，num就可以加1
	{
		num++;
	}

	ifs.close();	//关闭文件
	return num;
}

//初始化职工数组
void WorkerManager::init_Emp()	
{
	ifstream ifs;	//创建读文件流
	ifs.open(FILENAME, ios::in);	//打开文件，为读文件打开

	int id;
	string name;
	int dId;

	int index = 0;	//用作数组下标
	while (ifs >> id && ifs >> name && ifs >> dId)	//成功读完一个人的数据
	{
		Worker* worker = NULL;	//挨个临时储存每个职工
		//根据不同部门创建不同对象
		if (dId == 1)	//普通职工
		{
			worker = new Employee(id, name, 1);
		}
		else if (dId == 2)	//经理
		{
			worker = new Manager(id, name, 2);
		}
		else	//总裁
		{
			worker = new Boss(id, name, 3);
		}
		//存到数组中
		this->m_EmpArray[index] = worker;
		index++;	//数组下标++
	}
	ifs.close();
}

//显示职工信息
void WorkerManager::Show_Emp()
{
	//判断文件空标志是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//利用多态调用接口
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断职工是否存在（根据id判断）
int WorkerManager::IsExist(int id)
{
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)	//若找到了这个编号，返回数组下标
		{
			return i;
		}
	}
	return -1;
}

//删除职工
void WorkerManager::Del_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);	//判断该职工是否存在，返回其数组下标
		if (index == -1)	//若该职工不存在
		{
			cout << "删除失败，该职工不存在！" << endl;
		}
		else
		{
			//数组数据前移覆盖
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;	//职工总人数减一
			if (this->m_EmpNum == 0)
				this->m_FileIsEmpty = true;
			this->save();	//更新保存文件
			cout << "删除成功！" << endl;
		}
	}
	//删除成功后按任意键继续并清屏
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager::Mod_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请输入修改的职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);	//判断该职工是否存在，返回其数组下标
		if (index == -1)	//若该职工不存在
		{
			cout << "修改失败，该职工不存在！" << endl;
		}
		else
		{
			delete this->m_EmpArray[index];	//为什么要delete，直接修改替换不可以吗？ 因为修改职工后对象可能会改变，不是简单的修改内容
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "查到了编号为" << id << "的职工，请输入新的职工编号：" << endl;
			cin >> newId;
			cout << "请输入新的职工姓名：" << endl;
			cin >> newName;
			cout << "请输入新的岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			if (dSelect == 1)
			{
				worker = new Employee(newId, newName, 1);
			}
			else if (dSelect == 2)
			{
				worker = new Manager(newId, newName, 2);
			}
			else if (dSelect == 3)
			{
				worker = new Boss(newId, newName, 3);
			}
			else
			{
				cout << "输入错误！" << endl;
			}
			this->m_EmpArray[index] = worker;	//更新到数组中
			cout << "修改成功!" << endl;
			this->save();	//保存到文件中
		}
	}
	//删除成功后按任意键继续并清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请选择查找的方式：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;

		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "请输入要查找的职工编号：" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();	//多态实现的显示职工信息
			}
			else
			{
				cout << "查找失败!该职工不存在" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的职工姓名：" << endl;
			cin >> name;
			bool flag = false;	//用于标志是否找到，默认为flase
			int num = 0;	//用于记录重名情况下一共有几人重名
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (name == this->m_EmpArray[i]->m_Name)
				{
					cout << "查找成功！该职工信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
					num++;
				}
			}
			if (num>1)
			{
				cout << "有重名情况，该姓名的职工有" << num << "位" << endl;
			}
			if (flag == false)
			{
				cout << "查找失败！该职工不存在!" << endl;
			}
			
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
		}	
	}
	//查找成功后按任意键继续并清屏
	system("pause");
	system("cls");
}

//排序
void WorkerManager::Sort_Emp()
{
	//先判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空！" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.按职工编号升序" << endl;
		cout << "2.按职工编号降序" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)	//升序
		{
			Worker* worker = NULL;
			for (int i = 0; i < this->m_EmpNum - 1; i++)	//n个数需要冒泡排序n-1趟
			{
				bool flag = false;	//用于标志一趟排序中是否发生了交换，若未发生交换说明已经排序成功，结束循环
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)	//每次交换都可以将一个最大数或最小数移动到其应该在的位置，所有每次需要比较的数都减一
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
						flag = true;
					}
				}
				if (!flag)
					break;
			}
		}
		else if (select == 2)	//降序
		{
			Worker* worker = NULL;
			for (int i = 0; i < this->m_EmpNum - 1; i++)	//n个数需要冒泡排序n-1趟
			{
				bool flag = false;	//用于标志一趟排序中是否发生了交换，若未发生交换说明已经排序成功，结束循环
				for (int j = 0; j < this->m_EmpNum - 1 - i; j++)	//每次交换都可以将一个最大数或最小数移动到其应该在的位置，所有每次需要比较的数都减一
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
						flag = true;
					}
				}
				if (!flag)
					break;
			}
		}
		else
		{
			cout << "输入错误！" << endl;
		}
		this->Show_Emp();	//输出排序后的职工
		this->save();	//更新保存文件
	}		
	//排序成功后按任意键继续并清屏
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()	
{
	//这种方法每次都是将全部数据重新写入文件
	ofstream ofs;	//创建流对象
	ofs.open(FILENAME, ios::out);	//打开方式
	for (int i = 0; i<this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();	//关闭文件
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "请再次确认是否要清空文件：" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);	//打开方式为：删除文件后重新创建
		//也可直接写成：ofstream ofs(FILENAME, ios::trunc);、
		ofs.close();
		//释放堆区数据，打开文件的时候构造函数在堆区开辟的空间（析构函数功能不全，且执行析构函数的时候有判断条件，不会重复释放）
		if (this->m_EmpArray)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i])	//判断每一个数组中每一个对象是否有在堆区开辟空间，如果有，则逐个释放
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;	//职工个数归零
			this->m_FileIsEmpty = true;	//文件空标志置为空
		}
	}
	system("pause");
	system("cls");
}

//退出系统
void WorkerManager::exitSystem()	
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);	//无论在哪里调用，程序都可以直接退出
}

//析构函数，cpp文件中实现
WorkerManager::~WorkerManager()	
{
	//释放堆区数据
	if (this->m_EmpArray)	
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i])	//判断每一个数组中每一个对象是否有在堆区开辟空间，如果有，则逐个释放
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
