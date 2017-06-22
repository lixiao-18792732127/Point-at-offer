// 调整顺序使奇数位位于偶数位的前面
#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
//判断时候为偶数
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
	int left = 0;//定义一个指向数组首元素的指针
	int right = length - 1;//定义一个指向数组最后一个元素的指针
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
	printf("请输入数组的内容->\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	int lenght = sizeof(arr) / sizeof(arr[0]);
	printf("调整之前的数组：");
	PrintfArr(arr);
	printf("调整之后的数组：");
	ReOrderEven(arr, lenght);
	PrintfArr(arr);
	system("pause");
	return 0;
}
