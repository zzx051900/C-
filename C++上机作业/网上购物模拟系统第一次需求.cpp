#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

const int Max_num = 100;

//单个商品结构体，包括ID、名称、品牌、价格、数量
struct item
{
	int id;
	string name;
	string brand;
	float price;
	int amount;
};

//用户结构体，包括用户名称，用户密码，收货地址，用户购物车
struct user
{
	string name;
	string password;
	string address = "none";
	item shopping_car[Max_num];//购物车由商品结构体数组实现
	int shopping_car_num = 0; //购物车中商品数量
};

//新建一个购物系统的类
class Shopping
{
private:
	const string admin_ID = "id123456"; //管理员ID
	const string admin_passwd = "123456"; //管理员密码
	const char all_users_address[20] = "E:\\C++练习\\用户.txt"; //用户列表文件地址

public:
	user all_users[Max_num]; //用户列表，由用户结构体数组实现
	int user_num = 0; //用户列表数量

	void show();  //显示主界面
	void users_enter(); //用户登录界面
	void users_register(); //用户注册界面
	void administrator_enter(); //管理员登录界面
	void admin_operate();//管理操作页面
	void read_all_the_users();//读取用户列表
	void write_all_the_users();//写入用户列表
	void visit_items();//用户查看商品
	void user_operate(int index, user* this_user);//用户操作界面
};
	

int main() //短小精悍的main函数(bushi
{
	Shopping sp;
	sp.show();
	system("pause");
	return 0;
}

void Shopping::show()
{
	cout << "====================================================================================================" << endl;
	cout << "==================1.用户登录     2.用户注册     3.管理员登录     4.退出系统     5.查询商品============================" << endl;
	cout << "====================================================================================================" << endl;

	int n;
	cout << "输入操作：" << endl;
	cin >> n;
	while (n != 4)
	{
		switch (n)
		{
		case 1:
			users_enter();//用户登录
			break;
		case 2:
			users_register();//用户注册
			break;
		case 3:
			administrator_enter();//管理员登录
			break;
		case 5:
			visit_items();//查询商品
		default:
			cout << "请重新输入" << endl;
			break;
		}
		cout << "====================================================================================================" << endl;
		cout << "==================1.用户登录     2.用户注册     3.管理员登录     4.退出系统============================" << endl;
		cout << "====================================================================================================" << endl;
		cout << "输入操作：" << endl;
		cin >> n;
	}
	cout << "欢迎下次使用" << endl;
}

//用户登录界面 附加功能：密码错误提示及次数上限
void Shopping::users_enter()
{
	read_all_the_users(); //读取用户列表


	int cnt = 0;
	while (cnt < 3)
	{
		string name, passwd;
		cout << "输入用户名：";
		cin >> name;
		cout << "输入密码：";
		cin >> passwd;

		int i;
		for (i = 0; i < user_num; i++)
		{
			if (name == all_users[i].name && passwd == all_users[i].password)
			{
				cout << "*******" << endl;
				cout << "登录成功！" << endl;
				cout << "*******" << endl;
				user_operate(i, &all_users[i]); //传入用户在用户列表中的下标和结构体指针
				break;
			}
		}
		if (i < user_num)
			break;
		else if (i == user_num)
		{
			cnt++;
			cout << "用户名或密码错误，请再次输入用户名与密码，";
			cout << "你还有" << 3 - cnt << "次机会" << endl;
		}
	}

	if (cnt == 3)
		cout << "错误次数已达上限，系统关闭！" << endl;
}

//用户注册界面 附加功能：已存在的用户名或过短的密码都不符合要求，需要重新输入
void Shopping::users_register()
{
	read_all_the_users(); //读取用户列表

	string name, passwd;
	cout << "输入用户名：";
	cin >> name;
	while (true)
	{
		int i;
		for (i = 0; i < user_num; i++)
		{
			if (all_users[i].name == name)
			{
				cout << "用户名已存在，请重新输入！" << endl;
				break;
			}
		}
		if (i == user_num) //合法的用户名
			break;
		else if (i < user_num)
		{
			cout << "输入用户名：";
			cin >> name;
		}
	}

	cout << "输入密码：";
	cin >> passwd;
	while (passwd.size() <= 3)
	{
		cout << "密码长度太短，请重新输入！" << endl;
		cout << "输入密码：";
		cin >> passwd;
	}

	//新建一个用户
	user_num++;
	all_users[user_num - 1].name = name;
	all_users[user_num - 1].password = passwd;
	all_users[user_num - 1].shopping_car_num = 0;
	


	write_all_the_users(); //写入用户列表

	//注册成功并登录
	cout << "***************" << endl;
	cout << "注册成功！登录成功！" << endl;
	cout << "***************" << endl;
	user_operate(user_num - 1, &all_users[user_num - 1]);//传入用户在用户列表中的下标和结构体指针

}


//用户相关操作
//用户操作界面
void Shopping::user_operate(int index, user* this_user)
{
	cout << "=========================================================================================" << endl;
	cout << "1.注销登录     2.查看商品     3.商品搜索     4.添加商品至购物车\033[0m" << endl;
	cout << "\033[33;1m5.删除购物车商品     6.查看购物车     7.结账     8.修改密码	9.管理收货地址\033[0m" << endl;
	cout << "输入操作：";
	int n;
	cin >> n;
	
	while (n != 1)
	{
		switch (n)
		{
		case 2:
			visit_items();
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			
			break;
		case 9:
			
			break;
		default:
			cout << "\033[31;1m错误的操作指令！\033[0m" << endl;
			break;
		}
		cout << "=========================================================================================" << endl;
		cout << "\033[33;1m1.注销登录     2.查看商品     3.商品搜索     4.添加商品至购物车\033[0m" << endl;
		cout << "\033[33;1m5.删除购物车商品     6.查看购物车     7.结账     8.修改密码	9.管理收货地址\033[0m" << endl;
		cout << "输入操作：" << endl;
		cin >> n;
	}
	cout << "退出登录！" << endl;
}

//管理员登录界面 附加功能：密码错误提示及次数上限
void Shopping::administrator_enter()
{

	int cnt = 0;
	while (cnt < 3)
	{
		cout << "输入管理员ID：";
		string id, passwd;
		cin >> id;
		cout << "输入管理员密码：";
		cin >> passwd;
		if (id == admin_ID && passwd == admin_passwd)
		{
			cout << "*******" << endl;
			cout << "登录成功！" << endl;
			cout << "*******" << endl;
			admin_operate();
			break;
		}
		else
		{
			cnt++;
			cout << "ID或密码错误，请再次输入管理员ID与密码，";
			cout << "你还有" << 3 - cnt << "次机会" << endl;
		}
	}
	if (cnt == 3)
		cout << "错误次数已达上限，系统关闭！" << endl;
}

//管理员操作界面
void Shopping::admin_operate()
{
	cout << "=========================================================================================" << endl;
	cout << "\033[33;1m0.注销登录     1.查询商品     2.增加商品     3.删除商品     4.修改产品数量     5.查询售货清单\033[0m" << endl;
	cout << "输入操作：";
	int n;
	cin >> n;
	while (n != 0)
	{
		switch (n)
		{
		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		default:
			cout << "\033[31;1m错误的操作指令！\033[0m" << endl;
			break;
		}
		cout << "=========================================================================================" << endl;
		cout << "\033[33;1m0.注销登录     1.查询商品     2.增加商品     3.删除商品     4.修改产品数量     5.售货清单\033[0m" << endl;
		cout << "输入操作：" << endl;
		cin >> n;
	}
	cout << "退出登录！" << endl;
}


//读取用户列表
void Shopping::read_all_the_users()
{
	user_num = 0;//先将用户数量置为0

	ifstream in_file(all_users_address, ios::in);
	if (in_file.is_open() == 0)
		cout << "打开文件错误！" << endl;
	string a, b;
	in_file >> a >> b; //读入文件表头

	while (in_file.peek() != EOF)
	{
		in_file >> all_users[user_num].name;
		in_file >> all_users[user_num].password;
		if (all_users[user_num].name[0] >= 'a'&& all_users[user_num].name[0] <= 'z') //用于规避文件结尾的空白行
			user_num++;
	}
}

//写入用户列表
void Shopping::write_all_the_users()
{
	//更新的用户列表写入库存文件
	ofstream out_file(all_users_address, ios::out);
	out_file << "用户名\t" << "密码\t\t" << endl;
	for (int i = 0; i < user_num; i++)
	{
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].name << "\t";
		out_file.width(10);
		out_file.setf(ios::left);
		out_file << all_users[i].password << "\t";
		out_file << endl;
	}
}

//用户查看商品，读入库存文件，再按要求输出
void Shopping::visit_items()
{

}