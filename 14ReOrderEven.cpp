// ����˳��ʹ����λλ��ż��λ��ǰ��
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
//�ж�ʱ��Ϊż��
bool IsEven(int num)
{
	if (num % 2 == 0)
	{
		return true;
	}
	return false;
}

void ReOrderEven(int* arr,size_t length)
{
	int left = 0;//����һ��ָ��������Ԫ�ص�ָ��
	int right = length - 1;//����һ��ָ���������һ��Ԫ�ص�ָ��
	while (left < right)
	{
		while (left < right && !IsEven(arr[left]))
		{
			left++;
		}
		while (left < right && IsEven(arr[right]))
		{
			right--;
		}
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

void PrintfArr(int* arr)
{
	int length = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[10] = { 0 };
	printf("���������������->\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int lenght = sizeof(arr) / sizeof(arr[0]);
	printf("����֮ǰ�����飺");
	PrintfArr(arr);
	printf("����֮������飺");
	ReOrderEven(arr, lenght);
	PrintfArr(arr);
	system("pause");
	return 0;
}
