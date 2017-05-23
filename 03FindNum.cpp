//在一个二维数组中，每一行都按照从左到右递增的顺序排序，
//每一类都按照从上到下递增的顺序排列。请完成一个函数，
//输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
#include<iostream>
using namespace std;
#include<assert.h>
const int M = 3;
const int N = 3;

bool Find(const int *a, int x, int y,int &key)
{
	assert(a);
	while (x < M&&x >= 0 && y < N&&y >= 0)
	{
		int num = a[x*M + y];
		if (key>num)//如果查找的数字大于第一行最后一个数字，则x++；
		{
			x++;
		}
		else if(key<num)//如果查找的数字小于某一行最后一个数字，则y--；
		{
			y--;
		}
		else
		{
			return true;
		}
	}
	return false;
}
void Judge(int ret, int key)
{
	if (ret == 1)
	{
		cout << "数字" << key << "找到了!" << endl;
	}
	else//if (ret=0)
	{
		cout << "数字" << key << "没有找到！" << endl;
	}
}

int main()
{
	int a[9] = { 1, 2, 3, 
		         4, 5, 6,
		         7, 8, 9 };
	int num = 0;
	cout << "请输入要查找的数：" << endl;
	cin >> num;
	int ret = Find(a, 0, M - 1, num);
	Judge(ret,num);
	system("pause");
	return 0;
}