#include<iostream>
#include<string>
using namespace std;

//�ֱ�������ͨд���Ͷ�̬д��ʵ�ּ�����

//��ͨд��
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
		//���Ҫ�ṩ�µĹ��ܣ�����Ҫ�޸�Դ��
		//������ʵ�Ŀ������ᳫһ��ԭ�򣺿���ԭ�򣨶���չ���п��������޸Ľ��йرգ�
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

//�ö�̬ʵ�ּ�����
//��̬�����ĺô���1.��֯�ṹ����	2.�ɶ���ǿ	3.����ǰ�ںͺ�����չ�Լ�ά���Ը�

//ʵ�ּ�����������
class AbstractCalculator
{
public:
	virtual int getResult()	//�麯���������������д
	{
		return 0;
	}
	int m_Num1;
	int m_Num2;
};

//�ӷ���������
class AddClaculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;;
	}
};

//������������
class SubClaculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;;
	}
};

//�˷���������
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
	//�ӷ�����
	AbstractCalculator *abc = new AddClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult()  << endl;
	delete abc;	//�������ٵ�����Ҫ����
	//��������
	abc = new SubClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;	//�������ٵ�����Ҫ����
	//�˷�����
	abc = new MulClaculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 20;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;	//�������ٵ�����Ҫ����
}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;
}