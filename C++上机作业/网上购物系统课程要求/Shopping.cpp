#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include"Shopping.h"
using namespace std;

Shopping::Shopping()
{
	char all_items_address[20] = "库存.txt"; //库存文件地址
	char sales_list_address[20] = "已售清单.txt"; //售货清单文件地址
	char all_users_address[20] = "用户.txt"; //用户列表文件地址
	char users_shopping_address[20] = "收货地址.txt"; //用户收货地址文件地址
}


//显示主界面	√
void Shopping::show()
{
	cout << "===============================================================================================================" << endl;
	cout << "欢迎使用 购物系统" << "请输入对应操作" << endl;
	cout << "===============================================================================================================" << endl;
	cout << "1.用户登录		2.用户注册		3.管理员登录		4.退出系统		5.用户查看商品信息" << endl;
	int n;
	cout << "输入操作：" << endl;
	cin >> n;
	while (n != 4)
	{
		switch (n)
		{
		case 1:
			users_enter();
			break;
		case 2:
			users_register();
			break;
		case 3:
			administrator_enter();
			break;
		case 5:
			Shopping::show_items();
			break;
		case 8:
			admin_operate(); //直接登入管理员界面便于debug
			break;
		case 9:
			user_operate(0, &all_users[0]);
			break;
		default:
			cout << "错误的操作指令！" << endl;
			break;
		}
		cout << "===============================================================================================================" << endl;
		cout << "1.用户登录		2.用户注册		3.管理员登录		4.退出系统		5.用户查看商品信息" << endl;
		cout << "===============================================================================================================" << endl;
		cout << "输入操作：" << endl;
		cin >> n;
	}
	cout << "欢迎下次使用！" << endl;
}

//用户登录界面 √
void Shopping::users_enter()	//附加功能：密码错误提示及次数上限
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
			if ((name.compare(all_users[i].name) == 0) && (passwd.compare(all_users[i].password) == 0))
			{
				cout << "===========" << endl;
				cout << "登录成功！" << endl;
				cout << "===========" << endl;
				user_operate(i, &all_users[i]); //传入用户在用户列表中的下标和该用户的引用类型
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

//用户注册界面	√
void Shopping::users_register()	//附加功能：已存在的用户名或过短的密码都不符合要求，需要重新输入
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

	all_users[user_num - 1].shopping_car_num = 0;	//购物车中商品数量置零
	write_shopping_car(&all_users[user_num - 1]); //创建购物车文件


	write_all_the_users(); //写入用户列表

	//注册成功并登录
	cout << "=================*" << endl;
	cout << "注册成功！登录成功！" << endl;
	cout << "=================*" << endl;
	user_operate(user_num - 1, &all_users[user_num - 1]);//传入用户在用户列表中的下标和结构体指针

}

//管理员登录界面 √
void Shopping::administrator_enter()	//附加功能：密码错误提示及次数上限
{

	int cnt = 0;
	while (cnt < 3)
	{
		cout << "输入管理员ID：";
		string id, passwd;
		cin >> id;
		cout << "输入管理员密码：";
		cin >> passwd;
		if (((id.compare(admin_ID)) == 0) && ((passwd.compare(admin_passwd)) == 0))
		{
			cout << "=========" << endl;
			cout << "登录成功！" << endl;
			cout << "=========" << endl;
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


//文件相关操作：//读取库存文件	√
void Shopping::read_all_the_items()
{
	item_num = 0;//先将库存货物种类置为0

	ifstream in_file;
	in_file.open("库存.txt", ios::in);

	if (!in_file.is_open())
		cout << "打开文件错误！" << endl;
	string a, b, c, d, e;

	in_file >> a >> b >> c >> d >> e;//读入文件表头

	while (in_file >> all_items[item_num].id &&
		in_file >> all_items[item_num].name &&
		in_file >> all_items[item_num].brand &&
		in_file >> all_items[item_num].price &&
		in_file >> all_items[item_num].amount)//读入库存数据
	{
		item_num++;
	}
}

//写入库存文件	√
void Shopping::write_all_the_items()
{
	//更新的商品信息写入库存文件
	ofstream out_file;
	out_file.open("库存.txt", ios::out);

	out_file << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
	for (int i = 0; i < item_num; i++)
	{
		out_file << all_items[i].id << "\t"
			<< all_items[i].name << "\t"
			<< all_items[i].brand << "\t"
			<< all_items[i].price << "\t"
			<< all_items[i].amount << "\t" << endl;
	}
}


//读取用户列表	√
void Shopping::read_all_the_users()
{
	user_num = 0;//先将用户数量置为0

	ifstream in_file;
	in_file.open("用户.txt", ios::in);

	//文件不存在的情况
	if (in_file.is_open() == 0)
	{
		cout << "文件不存在！" << endl;
		in_file.close();
		return;
	}
	else
	{
		in_file.close();
	}

	in_file.open("用户.txt", ios::in);
	string a, b;
	in_file >> a >> b; //读入文件表头
	//文件存在，但记录为空的情况
	char ch;
	in_file >> ch;	//读入文件中的一个字符，若文件为空，则读入的是EOF（？？？不太理解）
	if (in_file.eof())	//判断读入是否为EOF，若是，则为真
	{
		cout << "文件为空！" << endl;
		in_file.close();
		return;
	}
	else
	{
		in_file.close();
	}

	//文件存在，且存在数据
	in_file.open("用户.txt", ios::in);
	in_file >> a >> b; //读入文件表头
	while (in_file >> all_users[user_num].name && in_file >> all_users[user_num].password)
	{
		user_num++;	//用户数量++
	}
	in_file.close();
}

//写入用户列表	√
void Shopping::write_all_the_users()
{
	//更新的用户列表写入库存文件
	ofstream out_file;
	out_file.open("用户.txt", ios::out);
	out_file << "用户名\t" << "密码\t" << endl;
	for (int i = 0; i < user_num; i++)
	{
		out_file << all_users[i].name << "\t"
			<< all_users[i].password << "\t" << endl;
	}
}


//读取用户购物车	√
void Shopping::read_shopping_car(user* this_user)
{
	this_user->shopping_car_num = 0;//先将购物车商品种类置为0
	string shopping_car_address = this_user->name + ".txt";//设置购物车文件地址

	ifstream in_file;
	in_file.open(shopping_car_address, ios::in);

	if (in_file.is_open() == 0)
	{
		cout << "打开文件错误！" << endl;
	}

	string a, b, c, d, e;
	in_file >> a >> b >> c >> d >> e; //读入文件表头

	while (in_file >> this_user->shopping_car[this_user->shopping_car_num].id &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].name &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].brand &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].price &&
		in_file >> this_user->shopping_car[this_user->shopping_car_num].amount) //读入库存数据
	{
		this_user->shopping_car_num++;
	}
}

//写入用户购物车	√
void Shopping::write_shopping_car(user* this_user)
{
	//更新的用户购物车写入库存文件
	string shopping_car_address = this_user->name + ".txt"; //设置购物车文件地址
	ofstream out_file;
	out_file.open(shopping_car_address, ios::out);	//以写方式创建并打开
	out_file << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
	if (this_user->shopping_car_num != 0)
	{
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			out_file << this_user->shopping_car[i].id << "\t"
				<< this_user->shopping_car[i].name << "\t"
				<< this_user->shopping_car[i].brand << "\t"
				<< this_user->shopping_car[i].price << "\t"
				<< this_user->shopping_car[i].amount << "\t" << endl;
		}
	}
}


//管理员相关操作：	//管理员操作界面	√
void Shopping::admin_operate()
{
	cout << "======================================================================" << endl;
	cout << "0.注销登录     1.查询商品     2.增加商品     3.删除商品     4.修改产品信息" << endl;
	cout << "======================================================================" << endl;

	cout << "输入操作：";
	int n;
	cin >> n;
	while (n != 0)
	{
		switch (n)
		{
		case 1:
			show_items();
			break;
		case 2:
			add_item();
			break;
		case 3:
			delete_item();
			break;
		case 4:
			change_item();
			break;
		default:
			cout << "错误的操作指令！" << endl;
			break;
		}
		cout << "======================================================================" << endl;
		cout << "0.注销登录     1.查询商品     2.增加商品     3.删除商品     4.修改产品信息" << endl;
		cout << "======================================================================" << endl;

		cout << "输入操作：";
		cin >> n;
	}
	cout << "退出登录！" << endl;
}

//管理员查看商品	√
void Shopping::show_items()	//先读入库存文件，再进行输出
{
	read_all_the_items(); //读入库存文件

	//输出库存商品数据，数量为0的商品也要输出
	if (item_num == 0)
		cout << "当前库存为空！" << endl;

	else
	{
		cout << "============================================" << endl;
		cout << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
		for (int i = 0; i < item_num; i++)
		{
			if (all_items[i].amount >= 0 || all_items[i].amount == -1)
			{
				cout << all_items[i].id << "\t";
				cout << all_items[i].name << "\t";
				cout << all_items[i].brand << "\t";
				cout << all_items[i].price << "\t";
				cout << all_items[i].amount << "\t" << endl;
			}
		}
		cout << "============================================" << endl;
	}
}

//管理员添加商品	√
void Shopping::add_item()	//先读入库存文件，再添加商品，最后写入库存文件
{
	read_all_the_items();

	cout << "请输入要进货的商品ID：";

	int id;
	cin >> id;

	int i = 0;
	for (i = 0; i<item_num; i++)
	{
		if (all_items[i].id == id)
		{
			int n;
			cout << "新增该商品的数量为：";
			cin >> n;
			all_items[i].amount += n;
			cout << "新增成功！该商品现在的数量为" << all_items[i].amount << endl;
			break;
		}
	}
	if (i == item_num && item_num<Max_num) //没有找到对应的ID，新建一种商品
	{
		item_num++; //商品种类数+1

		all_items[item_num - 1].id = id;

		cout << "库存中没有找到对应ID，将自动新建一种商品，请输入该商品的名称：";
		cin >> all_items[item_num - 1].name;
		cout << "请输入该商品的品牌：";
		cin >> all_items[item_num - 1].brand;
		cout << "请输入该商品的价格：";
		cin >> all_items[item_num - 1].price;
		cout << "请输入该商品的数量：";
		cin >> all_items[item_num - 1].amount;
		cout << "添加成功！" << endl;
	}

	//更新的商品信息写入库存文件
	write_all_the_items();
}

//管理员删除商品	√
void Shopping::delete_item()	//先读入库存文件，再删除商品，最后写入库存文件
{
	read_all_the_items();

	cout << "请输入要删除的商品id：";
	int id;
	cin >> id;

	int i = 0;
	bool flag = false;	//用于标志是否删除成功
	for (i = 0; i < item_num; i++)
	{
		if (all_items[i].id == id)
		{
			//数据前移覆盖
			for (int j = i; j < item_num; j++)
			{
				all_items[j] = all_items[j + 1];
				item_num--;
				cout << "商品删除成功！" << endl;
				flag = true;
				break;
			}
			break;
		}
	}
	if (flag == false) //没有找到对应的id
		cout << "没有找到对应的商品！" << endl;

	//更新的商品信息写入库存文件
	write_all_the_items();
}

//管理员修改商品	√
void Shopping::change_item()	//先读入库存文件，再修改商品信息，最后写入库存文件
{
	read_all_the_items();

	cout << "请输入要修改的商品id：";
	int id;
	cin >> id;

	int i = 0;
	for (i = 0; i < item_num; i++)
	{
		if (all_items[i].id == id)
		{
			string str;

			cout << "请输入修改后的名称：";
			cin >> str;
			all_items[i].name = str;
			cout << "请输入修改后的品牌：";
			cin >> str;
			all_items[i].brand = str;
			cout << "请输入修改后的价格：";
			float x;
			cin >> x;
			if (x < 0)
				cout << "修改失败！价格不能为负！" << endl;
			else
				all_items[i].price = x;
			cout << "请输入修改后的数量：";
			int amt;
			cin >> amt;
			all_items[i].amount = amt;
			cout << "修改成功！" << endl;
			break;
		}
	}
	if (i == item_num) //没有找到对应的id
		cout << "没有找到对应的商品！" << endl;

	//更新的商品信息写入库存文件
	write_all_the_items();
}

//用户相关操作：//用户操作界面		√
void Shopping::user_operate(int index, user* this_user)
{
	cout << "==============================================================================" << endl;
	cout << "1.注销登录     2.查看商品     3.商品搜索     4.添加商品至购物车	5.删除购物车商品" << endl;
	cout << "6.查看购物车     7.结账     8.修改密码	9.修改购物车商品数量" << endl;
	cout << "==============================================================================" << endl;

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
			search_item();
			break;
		case 4:
			add_shopping_car(index, this_user);
			break;
		case 5:
			delete_shopping_car(index, this_user);
			break;
		case 6:
			visit_shopping_car(index, this_user);
			break;
		case 7:
			check_out(index, this_user);
			break;
		case 8:
			change_password(index, this_user);
			break;
		case 9:
			change_shopping_car(index, this_user);
			break;
		default:
			cout << "错误的操作指令！" << endl;
			break;
		}
		cout << "==============================================================================" << endl;
		cout << "1.注销登录     2.查看商品     3.商品搜索     4.添加商品至购物车	5.删除购物车商品" << endl;
		cout << "6.查看购物车     7.结账     8.修改密码	9.修改购物车商品数量" << endl;
		cout << "==============================================================================" << endl;
		cout << "输入操作：" << endl;
		cin >> n;
	}
	cout << "退出登录！" << endl;
}

//用户查看商品	√
void Shopping::visit_items()	//读入库存文件，再按要求输出
{
	read_all_the_items(); //读入库存文件

	//输出库存商品数据，数量为0的商品不需要输出
	if (item_num == 0)
	{
		cout << "当前库存为空！" << endl;
	}
	else
	{
		cout << "============================================" << endl;
		cout << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
		for (int i = 0; i < item_num; i++)
		{
			if (all_items[i].amount >= 0 || all_items[i].amount == -1)
			{
				cout << all_items[i].id << "\t";

				cout << all_items[i].name << "\t";

				cout << all_items[i].brand << "\t";

				cout << all_items[i].price << "\t";

				cout << all_items[i].amount << "\t";
				cout << endl;
			}
		}
		cout << "============================================" << endl;
	}
}

//用户搜索商品 √
void Shopping::search_item()	//扩展功能：可选择名称+品牌的搜索方式
{
	read_all_the_items(); //读取库存

	int flag = 0; //表示搜索是否成功
	cout << "请输入商品名称：";
	string name;
	cin >> name;

	for (int i = 0; i < item_num; i++)
	{
		if (all_items[i].amount > 0 && (all_items[i].name == name || (all_items[i].name.find(name) != string::npos))) //支持完全匹配和模糊匹配
		{
			if (flag == 0) //搜索到的第一个商品，输出表头，后序搜索成功的商品不需要输出表头
			{
				cout << "============================================" << endl;
				cout << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
				flag = 1;
			}
			//输出搜索结果
			cout << all_items[i].id << "\t";
			cout << all_items[i].name << "\t";
			cout << all_items[i].brand << "\t";
			cout << all_items[i].price << "\t";
			cout << all_items[i].amount << "\t";
			cout << endl;
		}
	}
	if (flag == 1) //搜索成功，输出表尾
		cout << "============================================" << endl;
	else //搜索失败，输出提示语
		cout << "未找到该商品，试试换一个词搜索吧！" << endl;
}

//用户添加商品至购物车	√
void Shopping::add_shopping_car(int index, user* this_user)
{
	read_all_the_items(); //读取库存
	read_shopping_car(this_user); //读取该用户购物车

	cout << "输入添加至购物车的商品id：";
	int id;
	cin >> id;
	cout << "输入添加至购物车的商品数量：";
	int amount;
	cin >> amount;

	int i;
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			int index = 0; //用来记录该商品在购物车中的下标
			for (int j = 0; j<item_num; j++)
			if (all_items[j].id = id)
				index = j;

			if (amount > all_items[index].amount)//添加数量超过库存，添加失败
			{
				cout << "添加失败！添加数量超过商品库存，请修改！" << endl;
				break;
			}

			else //添加成功 
			{
				this_user->shopping_car[i].amount += amount;
				cout << "--------------" << endl;
				cout << "加入购物车成功！" << endl;
				cout << "--------------" << endl;
				write_shopping_car(this_user);
				break;
			}
		}
	}

	if (i == this_user->shopping_car_num) //购物车中未找到对应ID
	{
		int j;
		for (j = 0; j<item_num; j++)
		if (all_items[j].id == id) //在库存中找到了对应ID
		{
			if (id > all_items[i].amount) //添加数量超过库存，添加失败
			{
				cout << "添加失败！添加数量超过商品库存，请修改！" << endl;
				break;
			}
			else //添加成功，购物车种类加一
			{
				this_user->shopping_car_num++;
				this_user->shopping_car[this_user->shopping_car_num - 1].id = id;
				this_user->shopping_car[this_user->shopping_car_num - 1].name = all_items[j].name;
				this_user->shopping_car[this_user->shopping_car_num - 1].brand = all_items[j].brand;
				this_user->shopping_car[this_user->shopping_car_num - 1].price = all_items[j].price;
				this_user->shopping_car[this_user->shopping_car_num - 1].amount = amount;
				write_shopping_car(this_user);
				cout << "--------------" << endl;
				cout << "加入购物车成功！" << endl;
				cout << "--------------" << endl;
				break;
			}
		}

		if (j == item_num)
		{
			cout << "店铺中没找到该ID对应的商品，请检查是否输入正确！" << endl;
		}
	}

	//展示购物车
	cout << "购物车中现在有：" << endl;
	visit_shopping_car(index, this_user);
}

//用户删除购物车商品	√
void Shopping::delete_shopping_car(int index, user* this_user)
{
	read_shopping_car(this_user); //读取该用户购物车

	cout << "输入待删除的商品ID：";
	int id;
	cin >> id;

	int i;
	bool flag = false;	//用于标志是否删除成功
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			for (int j = i; j < this_user->shopping_car_num; j++)
			{
				this_user->shopping_car[j] = this_user->shopping_car[j + 1];
			}
			this_user->shopping_car_num--;
			flag = true;
			write_shopping_car(this_user);
			cout << "--------" << endl;
			cout << "删除成功！" << endl;
			cout << "--------" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "购物车中没有该ID对应的商品，请检查是否输入错误！" << endl;

	//展示购物车
	cout << "购物车中现在有：" << endl;
	visit_shopping_car(index, this_user);

}

//用户修改购物车商品数量
void Shopping::change_shopping_car(int index, user* this_user)
{
	read_shopping_car(this_user); //读取该用户购物车

	cout << "输入待修改的商品ID：";
	int id;
	cin >> id;

	cout << "请输入要修改的数量：" << endl;
	int num;
	cin >> num;

	int i;
	bool flag = false;	//用于标志是否修改成功
	for (i = 0; i < this_user->shopping_car_num; i++)
	{
		if (this_user->shopping_car[i].id == id)
		{
			this_user->shopping_car[i].amount = num;
			flag = true;
			write_shopping_car(this_user);
			cout << "--------" << endl;
			cout << "修改成功！" << endl;
			cout << "--------" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "购物车中没有该ID对应的商品，请检查是否输入错误！" << endl;

	//展示购物车
	cout << "购物车中现在有：" << endl;
	visit_shopping_car(index, this_user);

}


//用户查看购物车	√
void Shopping::visit_shopping_car(int index, user* this_user)	//先读取对应的购物车文件再输出
{
	read_shopping_car(this_user); //读入购物车文件

	//输出库存商品数据，数量为0的商品也要输出
	if (this_user->shopping_car_num == 0)
	{
		cout << "当前购物车为空！去别处逛逛吧！" << endl;
	}
	else
	{
		cout << "=============================================" << endl;
		cout << "id\t" << "名称\t" << "品牌\t" << "价格\t" << "数量" << endl;
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			cout << this_user->shopping_car[i].id << "\t";
			cout << this_user->shopping_car[i].name << "\t";
			cout << this_user->shopping_car[i].brand << "\t";
			cout << this_user->shopping_car[i].price << "\t";
			cout << this_user->shopping_car[i].amount << "\t" << endl;
		}
		cout << "=============================================" << endl;
	}
}

//用户结账，需要修改用户购物车、库存和售货清单
void Shopping::check_out(int index, user* this_user)
{
	//读取库存，购物车，收货地址、售货清单
	read_all_the_items();
	read_shopping_car(this_user);

	visit_shopping_car(index, this_user);	//查看购物车

	if (this_user->shopping_car_num > 0)
	{

		float money = 0; //待付金额=sum(单价*数量)
		for (int i = 0; i < this_user->shopping_car_num; i++)
		{
			money += this_user->shopping_car[i].price * this_user->shopping_car[i].amount;	//每个商品的价格乘购买数量
		}
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "购物车商品总价为" << money << "元！" << endl;
		cout << "请选择您的操作：" << endl;
		cout << "0.取消购买" << endl;
		cout << "1.全部购买" << endl;
		cout << "2.选择购物车内部分商品购买" << endl;
		cout << "请输入操作：";
		int choice;
		cin >> choice;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		if (choice == 0)
		{
			cout << "已取消付款！" << endl;
		}
		else if (choice == 1)
		{
			//清空用户购物车
			for (int i = 0; i < this_user->shopping_car_num; i++)
			{
				this_user->shopping_car_num = 0;
			}
		}
		else if (choice == 2)
		{
			money = 0;
			while (1)
			{
				cout << "请输入购物车内要选择购买的商品id:";
				int id;
				cin >> id;
				cout << "请输入要购买该商品的数量:";
				int num;
				cin >> num;

				int i;
				bool flag = false;	//用于标志是否选择成功
				for (i = 0; i < this_user->shopping_car_num; i++)
				{
					if (this_user->shopping_car[i].id == id)
					{
						if (num == this_user->shopping_car[i].amount)
						{
							for (int j = i; j < this_user->shopping_car_num; j++)	//从购物车删除，数据前移
							{
								this_user->shopping_car[j] = this_user->shopping_car[j + 1];
							}
							this_user->shopping_car_num--;
							money += this_user->shopping_car[i].price * num;
							flag = true;
							break;
						}
						if (this_user->shopping_car_num > num)
						{

							this_user->shopping_car[i].amount -= num;
							money += this_user->shopping_car[i].price * num;
							flag = true;
							break;
						}
					}

				}
				if (flag == false)
				{
					cout << "购物车中没有该ID对应的商品，请检查是否输入错误！" << endl;
				}
				else
				{
					cout << "选择成功" << endl;
				}
				cout << "请输入您接下来的选择：" << endl;
				cout << "1.继续选择" << endl;
				cout << "0.结束选择" << endl;
				cout << "请输入：" << endl;
				int select;
				cin >> select;
				if (select == 0)
					break;
			}	//while结束
		}
		write_shopping_car(this_user);	//写入购物车文件

		//随机生成优惠券
		int m = rand() % 10;
		cout << "恭喜您获得一张面额为" << m << "的优惠券，优惠券码为123456，可以在付款时选择使用" << endl;

		//活动折扣
		cout << "商城今日上架活动：全部商品打九折" << endl;


		//输出提示语
		cout << "请选择是否使用优惠券" << endl;
		cout << "0.不使用" << endl;
		cout << "1.使用优惠券" << endl;
		int select = 0;
		cin >> select;
		if (select == 0)
		{
			cout << "----------------------------------" << endl;
			cout << "付款成功！九折优惠后付款金额为：" << money*0.9 << endl;
			cout << "----------------------------------" << endl;
		}
		else if (select == 1)
		{
			cout << "请输入优惠券码：" << endl;
			string str = "";
			cin >> str;
			if (str == "123456")
			{
				cout << "-----------------------------------------------" << endl;
				cout << "付款成功！九折优惠且使用优惠券后的付款金额为：" << (money*0.9 - m) << endl;
				cout << "-----------------------------------------------" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新选择" << endl;
		}
	}
}

//拓展功能：用户修改密码	√
void Shopping::change_password(int index, user* this_user)
{
	cout << "请输入原密码：";
	string old_pass;
	cin >> old_pass;

	if (old_pass == this_user->password)
	{
		string new_pass;
		cout << "请输入新密码：";
		cin >> new_pass;
		//设置新密码长度大于三位
		while (new_pass.size() <= 3)
		{
			cout << "密码长度太短，请重新输入！" << endl;
			cout << "输入密码：";
			cin >> new_pass;
		}
		this_user->password = new_pass;
		write_all_the_users();
		cout << "----------" << endl;
		cout << "修改成功！" << endl;
		cout << "----------" << endl;
	}

	else
		cout << "密码输入错误，修改失败！" << endl;
}

