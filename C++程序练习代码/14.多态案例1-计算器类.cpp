#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态写法实现计算器

//普通写法
class Calculator
{
public:
	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		//如果要提供新的功能，还需要修改源码
		//而在真实的开发中提倡一种原则：开闭原则（对拓展进行开发，对修改进行关闭）
	}
	int m_Num1;
	int m_Num2;
};

void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

//用多态实现计算器
//多态带来的好处：1.组织结构清晰	2.可读性强	3.对于前期和后期拓展以及维护性高

//实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int getResult()	//虚函数，在子类进行重写
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddClaculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;;
	}
};

//减法计算器类
class SubClaculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;;
	}
};

//乘法计算器类
class MulClaculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;;
	}
};

void test02()
{
	//加法运算
	AbstractCalculator *abc = new AddClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult()  << endl;
	delete abc;	//堆区开辟的数据要销毁
	//减法运算
	abc = new SubClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;	//堆区开辟的数据要销毁
	//乘法运算
	abc = new MulClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;	//堆区开辟的数据要销毁
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}