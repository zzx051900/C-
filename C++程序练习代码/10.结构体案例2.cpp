/*
案例描述：
- 设计一个英雄的结构体，包括成员姓名，年龄，性别
- 创建结构体数组，存放5名英雄
- 通过冒泡排序，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果
*/
#include<iostream>
#include<string>
using namespace std;


// 英雄的结构体
struct Hero
{
	string name;
	int age;
	string sex;
};

//打印所有英雄的信息
void printInfo(struct Hero heroArray[], int sz)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "英雄姓名:" << heroArray[i].name << " 年龄：" << heroArray[i].age << " 性别：" << heroArray[i].sex << endl;
	}
	cout << endl;
}

//冒泡排序
void bubblesort(struct Hero heroArray[], int sz)
{
	struct Hero temp;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (heroArray[j].age > heroArray[j + 1].age)//交换的是整个结构体变量，不只是交换年龄
			{
				temp = heroArray[j];
				heroArray[j] = heroArray[j + 1];
				heroArray[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//创建5名英雄的数组
	struct Hero heroArray[5] =
	{
		{ "aaa", 20, "男" },
		{ "bbb", 18, "女" },
		{ "ccc", 26, "男" },
		{ "ddd", 24, "男" },
		{ "eee", 19, "女" },
	};

	int sz = sizeof(heroArray) / sizeof(heroArray[0]);
	//打印排序前所有英雄的信息
	printInfo(heroArray, sz);

	//冒泡排序
	bubblesort(heroArray, sz);

	//打印排序后所有英雄的信息
	printInfo(heroArray, sz);

	system("pause");
	return 0;
}
