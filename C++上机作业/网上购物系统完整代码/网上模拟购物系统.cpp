#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<time.h>
#include"Shopping.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));//初始化随机数发生器，放在主函数前
	Shopping sp;

	sp.show();
	system("pause");
	return 0;
}