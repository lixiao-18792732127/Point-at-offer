#include<iostream>
using namespace std;
#include<assert.h>
double PowerWithUnsignedExpond(double base, size_t exponent)
{
	if (exponent == 0)//ָ��Ϊ0��ʱ��ֱ�ӷ���1
	{
		return 1;
	}
	if (exponent == 0)//ָ��Ϊ0��ʱ��ֱ�ӷ��ػ���
	{
		return base;
	}
	//�ݹ����ָ����һ�룬�õ�������ƽ�����ǵ�ǰ�Ľ�
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
	//���ָ���ľ���ֵ
	size_t absExponent = (size_t)(exponent);
	//���ָ��С��0����ָ�������ֵ
	if (exponent < 0)
	{
		absExponent = (size_t)(-exponent);
	}
	//�ݹ����
	double ret = PowerWithUnsignedExpond(base, absExponent);

	//���ָ��С��0������
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
	cout << " ���������m�ʹ���n��";
	cin >> m >> n;
	cout << "m��n�η�Ϊ��" << Power(m, n) << endl;
	system("pause");
	return 0;
}