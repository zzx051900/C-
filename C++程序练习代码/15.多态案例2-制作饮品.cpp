#include<iostream>
#include<string>
using namespace std;

class AbstractDrinking
{
public:
	virtual void Boil() = 0;		//煮水
	virtual void Brew() = 0;		//冲泡
	virtual void PourInCup() = 0;	//倒入杯中
	virtual void PutSomething() = 0;//加入辅料
	void makeDrink()	//制作饮品
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

class Coffee :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};

class Tea :public AbstractDrinking
{
public:
	virtual void Boil()
	{
		cout << "煮矿泉水" << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡茶叶" << endl;
	}
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};

void doWork(AbstractDrinking* abs)	//传入一个父类的指针 //这一个函数是因为咖啡和茶都要用到，所以单独封装了这一步
{
	abs->makeDrink();
	delete abs;
	abs = NULL;
}

void test01()
{
	//制作咖啡
	doWork(new Coffee);
	cout << "------------" << endl;
	//制作茶叶
	doWork(new Tea);
}

int main()
{
	test01();

	system("pause");
	return 0;
}