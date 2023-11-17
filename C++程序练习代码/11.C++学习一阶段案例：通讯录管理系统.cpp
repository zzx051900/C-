#include<iostream>
#include<string>
using namespace std;
#define MAX 1000//作用是方便后期维护，需要修改最大容量时很方便

//联系人结构体
struct Person
{
	string name;//姓名
	int sex;//性别
	int age;//年龄
	string phone;//电话
	string addr;//住址
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int size;//通讯录中已添加人数
};

//函数声明
void menu();//菜单功能
void addPerson(Addressbooks* abs);//添加联系人
void showPerson(Addressbooks* abs);//显示联系人
int isExist(Addressbooks* abs, string name); //检测联系人是否存在
void deletePerson(Addressbooks* abs);//删除联系人
void findPerson(Addressbooks* abs);//查找联系人
void modifyPerson(Addressbooks* abs);//修改联系人
void clearPerson(Addressbooks* abs);//清空联系人

int main()
{
	Addressbooks abs;//创建通讯录结构体变量
	abs.size = 0;//初始化通讯录中当前人数个数
	int select = 0;//存放用户输入的选择
	while (1)
	{
		menu();//调用菜单，除了退出通讯录的每个功能函数清屏后都会回到这里重新循环，菜单都会重新输出
		cin >> select;//用户输入选择
		switch (select)
		{
		case 1:
			addPerson(&abs);//添加联系人
			break;
		case 2:
			showPerson(&abs);//2.显示联系人
			break;
		case 3:
			deletePerson(&abs);//3.删除联系人	
			break;
		case 4:
			findPerson(&abs);//4.查找联系人
			break;
		case 5:
			modifyPerson(&abs);//5.修改联系人
			break;
		case 6:
			{
				cout << "请确认是否要清空全部联系人\n 0 --- 取消\n 1 --- 确认" << endl;
				int cle = 0;
				cin >> cle;
				if (cle == 1)
				{
					clearPerson(&abs);//6.清空联系人
				}
				else
				{
					cout << "欢迎下次使用" << endl;
					system("pause");//按任意键继续
				}
				break;
			}
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");//按任意键继续
			return 0;
			break;//0.退出通讯录
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

//菜单功能
void menu()
{
	cout << "*************************" << endl;
	cout << "******	1.添加联系人	******" << endl;
	cout << "******	2.显示联系人	******" << endl;
	cout << "******	3.删除联系人	******" << endl;
	cout << "******	4.查找联系人	******" << endl;
	cout << "******	5.修改联系人	******" << endl;
	cout << "******	6.清空联系人	******" << endl;
	cout << "******	0.退出通讯录	******" << endl;
	cout << "*************************" << endl;
}

//添加联系人
void addPerson(Addressbooks* abs)
{
	//先判断通讯录是否已满
	if (abs->size == MAX)
	{
		cout << "通讯已满，无法添加" << endl;
		return;
	}
	//姓名
	cout << "请输入姓名" << endl;
	cin >> abs->personArray[abs->size].name;//这里的访问方式有点疑惑；数组下标即为已有联系人个数
	//性别
	cout << "请输入性别" << endl;
	cout << "1 --- 男" << endl;
	cout << "2 --- 女" << endl;
	while (1)//需要循环输入判断，直到输入正确(1或2）
	{
		int sex = 0;
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personArray[abs->size].sex = sex;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	//年龄
	cout << "请输入年龄" << endl;
	while (1)//需要循环输入判断，直到输入正确(大于0且小于等于150）
	{
		int age = 0;
		cin >> age;
		if (age > 0 && age <= 150)
		{
			abs->personArray[abs->size].age = age;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	//电话
	cout << "请输入电话" << endl;
	cin >> abs->personArray[abs->size].phone;
	//家庭住址
	cout << "请输入家庭住址" << endl;
	cin >> abs->personArray[abs->size].addr;
	abs->size++;	//已有联系人数量加1
	cout << "添加成功" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//显示联系人
void showPerson(Addressbooks* abs)//可以用值传递，但浪费空间，所以用地址传递；是不是用const修饰更好？
{
	if (abs->size == 0)
	{
		cout << "记录为空" << endl;
	}
	for (int i = 0; i < abs->size; i++)
	{
		cout << "姓名：" << abs->personArray[i].name << "\t";
		cout << "性别：" << (abs->personArray[i].sex == 1 ? "男" : "女") << "\t";//使用了一个3目运算符，若为1，则输出男；不为1，则输出女
		cout << "年龄：" << abs->personArray[i].age << "\t";
		cout << "电话：" << abs->personArray[i].phone << "\t";
		cout << "住址：" << abs->personArray[i].addr << "\t";
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//检测联系人是否存在
int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->size; i++)
	{
		if (abs->personArray[i].name == name)
		{
			return i;//找到了，返回联系人数组下标
		}
		return -1;//如果遍历结束都没有找到，则返回-1
	}
}

//删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//检测联系人是否存在
	int ret = isExist(abs, name);//这里的abs已经是指针类型，不需要再取地址
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//将要删除联系人后面的联系人信息依次前移，最后联系人数量减一
		for (int i = ret; i < abs->size; i--)
		{
			abs->personArray[i] = abs->personArray[i + 1];//可以直接将整个联系人结构体赋过去
		}
		abs->size--;
		cout << "删除成功" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//检测联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "找到了该联系人，信息如下：" << endl;
		cout << "姓名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";//使用了一个3目运算符，若为1，则输出男；不为1，则输出女
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phone << "\t";
		cout << "住址：" << abs->personArray[ret].addr << "\t";
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//修改联系人
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//检测联系人是否存在
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//姓名
		cout << "请输入修改后的姓名" << endl;
		cin >> abs->personArray[abs->size].name;//这里的访问方式有点疑惑；数组下标即为已有联系人个数
		//性别
		cout << "请输入修改后的性别" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		while (1)//需要循环输入判断，直到输入正确(1或2）
		{
			int sex = 0;
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->size].sex = sex;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//年龄
		cout << "请输入修改后的年龄" << endl;
		while (1)//需要循环输入判断，直到输入正确(大于0且小于等于150）
		{
			int age = 0;
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[abs->size].age = age;
				break;
			}
			else
			{
				cout << "输入有误，请重新输入" << endl;
			}
		}
		//电话
		cout << "请输入修改后的电话" << endl;
		cin >> abs->personArray[abs->size].phone;
		//家庭住址
		cout << "请输入修改后的家庭住址" << endl;
		cin >> abs->personArray[abs->size].addr;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}

//清空联系人
void clearPerson(Addressbooks* abs)
{
	abs->size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}