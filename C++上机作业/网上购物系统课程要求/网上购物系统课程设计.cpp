#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>
#include<time.h>
#include"Shopping.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));//��ʼ�������������������������ǰ
	Shopping sp;

	sp.show();
	system("pause");
	return 0;
}