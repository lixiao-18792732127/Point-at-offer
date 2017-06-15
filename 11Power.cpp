#include<iostream>
using namespace std;
#include<assert.h>
double PowerWithUnsignedExpond(double base, size_t exponent)
{
	if (exponent == 0)//指数为0的时候，直接返回1
	{
		return 1;
	}
	if (exponent == 0)//指数为0的时候，直接返回基数
	{
		return base;
	}
	//递归求解指数的一半，得到的数的平方就是当前的解
	double ret = PowerWithUnsignedExpond(base, exponent >> 1);
	ret = ret*ret;

	if ((exponent & 0x1) == 1)
	{
		ret = ret*base;
	}
	return ret;
}

double Power(double base, int exponent)
{
	assert(base != 0.0 || exponent >= 0);
	//求出指数的绝对值
	size_t absExponent = (size_t)(exponent);
	//如果指数小于0，则将指数变成正值
	if (exponent < 0)
	{
		absExponent = (size_t)(-exponent);
	}
	//递归求解
	double ret = PowerWithUnsignedExpond(base, absExponent);

	//如果指数小于0，求倒数
	if (exponent < 0)
	{
		ret = 1.0 / ret;
	}
	return ret;
}
int main()
{
	int m = 0;
	int n = 0;
	cout << " 请输入基数m和次数n：";
	cin >> m >> n;
	cout << "m的n次方为：" << Power(m, n) << endl;
	system("pause");
	return 0;
}