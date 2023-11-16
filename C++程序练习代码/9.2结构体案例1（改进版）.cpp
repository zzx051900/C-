/*
案例描述：学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下：
- 设计学生和老师的结构体，其中在老师的结构体中有老师的姓名和一个存放5名学生的数组作为成员
- 学生的成员有姓名、考试分数
- 创建数组存放3名老师，通过函数给每个老师及所带学生赋值
- 最终打印出老师数据以及老师所带学生的数据
*/
//实现了具体输入
#include<iostream>
#include<string>
using namespace std;

//学生的结构体
struct Student
{
	string sName;
	int score;
};


// 老师的结构体
struct Teacher
{
	string tName;
	struct Student sArray[5];
};

//赋值函数,开辟空间并赋值
void allocateSpace(struct Teacher tArray[], int sz)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < sz; i++)
	{

		cin >> tArray[i].tName;
		for (int j = 0; j < 5; j++)
		{
			cin >> tArray[i].sArray[j].sName;

			cin >> tArray[i].sArray[j].score;
		}
	}
}

//打印所有老师及所带学生的信息
void printInfo(struct Teacher tArray[], int sz)
{
	for (int i = 0; i < sz; i++)
	{
		cout << "老师姓名：" << tArray[i].tName << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t学生姓名:" << tArray[i].sArray[j].sName << " 分数：" << tArray[i].sArray[j].score << endl;
		}
	}
	cout << endl;
}

int main()
{
	//创建3名老师的数组
	struct Teacher tArray[3];

	//通过函数给3名老师的信息赋值，并给老师所带的学生信息赋值
	int sz = sizeof(tArray) / sizeof(tArray[0]);
	allocateSpace(tArray, sz);

	//打印所有老师及所带学生的信息
	printInfo(tArray, sz);

	system("pause");
	return 0;
}
