#include<iostream>
using namespace std;
bool g_bInputInvalid = false;
bool CheckInvalidArr(int *number, int length)
{
	g_bInputInvalid = false;
	if (number == NULL && length <= 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}
bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}
	bool IsMoreThanHalf = true;
	if (times * 2 <= length)
	{
		g_bInputInvalid = true;
		IsMoreThanHalf = false;
	}
	return IsMoreThanHalf;
}
int MoreThanHalfNum(int* numbers, int length)
{
	if (CheckInvalidArr(numbers, length))
	{
		return 0;
	}
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	if (!CheckMoreThanHalf(numbers, length, result))
	{
		result = 0;
	}
	return result;
}
int main()
{
	int arr[20] = { 0 };
	cout << "请输入元素的个数->" << endl;
	int n = 0;
	cin >> n;
	cout << "请输入数组的元素->" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int ret = MoreThanHalfNum(arr, n);
	cout << "超过数组一半的数字为：" << ret << endl;
	system("pause");
	return 0;
}