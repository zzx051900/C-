#include<iostream>
#include<string>
using namespace std;

//抽象CPU类
class CPU
{
public:
	//抽象计算函数
	virtual void calculate() = 0;	//纯虚函数
};

//抽象显卡类
class VideoCard
{
public:
	//抽象显示函数
	virtual void display() = 0;	//纯虚函数
};

//抽象内存条类
class Memory
{
public:
	//抽象存储函数
	virtual void storage() = 0;	//纯虚函数
};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem)	//有参构造
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	void work()	//零件工作函数，调用具体接口
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer()
	{
		//释放CPU零件
		if (m_cpu)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		//释放显卡零件
		if (m_vc)
		{
			delete m_vc;
			m_cpu = NULL;
		}
		//释放内存条零件
		if (m_mem)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;	//CPU的零件指针
	VideoCard* m_vc;	//显卡零件指针	
	Memory* m_mem;	//内存条零件指针
};

//具体厂商：
	//Intel厂商:
		//CPU
class IntelCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算" << endl;
	}
};
		//显卡
class IntelVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示" << endl;
	}
};
		//内存条
class IntelMemory  :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储" << endl;
	}
};

	//Lenovo厂商：
		//CPU
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算" << endl;
	}
};
		//显卡
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示" << endl;
	}
};
		//内存条
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储" << endl;
	}
};

//测试组装不同电脑
void test01()
{
	//第一台电脑零件（用Intel的电脑零件）
	CPU* intelCPU = new IntelCPU;	//父类指针指向子类对象，多态	//堆区创建
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;

	//创建第一台电脑
	cout << "第一台电脑开始工作" << endl;
	Computer* computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	computer1->work();
	delete computer1;	//此时只释放了电脑类指针在堆区的内存，而零件在堆区的内存还没有释放

	//创建第二台电脑（用Lenovo的电脑零件）
	cout << "----------------" << endl;
	cout << "第二台电脑开始工作" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	//创建第三台电脑（混合搭配）
	cout << "----------------" << endl;
	cout << "第三台电脑开始工作" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}

int main()
{
	test01();

	system("pause");
	return 0;
}