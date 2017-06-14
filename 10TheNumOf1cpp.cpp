//Q:请实现一个函数，输入一个整数，输出该数二进制中的
//1的个数。例如：把9表示成二进制是1001，有2位是1.因此，如果输入是9
//改函数输出2。
#include<iostream>
using namespace std;
//int TheNumOf1(int num)//使用模除法解决
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
//}
//int TheNumOf1(unsigned int num)//为了避免传来的值是负数
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
//}

//int TheNumOf1(unsigned int num)//优化，每一个数都是32位的比特位
//{
//	int count = 0;
//	for (int i = 1; i < 32; i++)
//	{
//		if (num % 2 == 1)
//		{
//			count++;
//		}
//		num = num / 2;
//	}
//	return count;
}

int TheNumOf1(unsigned int num)
{
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0; 
	int ret = 0;
	cout << "请输入一个数字：";
	cin >> num;
	ret = TheNumOf1(num);
	cout << num << "的二进制数中的1的个数为：" << ret << endl;
	system("pause");
	return 0;
}