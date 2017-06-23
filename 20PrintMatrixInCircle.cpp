#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void PrintArr(int *arr, int Row, int Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			printf("%5d", arr[i*Row + j]);
		}
		cout << endl;
	}
}
void PrintMatrixInCircle(int *arr,int Row, int Col,int start)
{
	int endX = Col - start;
	int endY = Row - start;
	//从左向右打印
	for (int i = start; i < endX; ++i)
	{
		int num = arr[start*Row + i];
		cout << num << " ";
	}

	//从上向下进行打印，
	if (start < endY - 1)
	{
		for (int i = start + 1; i < endY; ++i)
		{
			int num = arr[i*Col + endX - 1];
			cout << num << " ";
		}
	}
	//从右向左打印
	if (start < endY - 1)
	{
		for (int j = endX - 2; j>start; --j)
		{
			int num = arr[(endY - 1)*Col + j];
			cout << num << " ";
			//printf("%3d", &num);
		}
	}

	if (start < endX - 1 && start < endY - 1)
	{
		for (int i = endY - 1; i>start; --i)
		{
			int num = arr[i*Col + start];
			cout << num << " ";
		}
	}
}
void PrintMatrix(int *arr, int Row, int Col)
{
	if (arr == NULL || Col <= 0 || Row <= 0)
	{
		return;
	}
	int start = 0;
	while (Col > start * 2 && Row > start * 2)
	{
		PrintMatrixInCircle(arr, Row, Col, start);
		++start;
	}
}

int main()
{
	int Row = 0;//行数
	int Col = 0;//列数
	int i = 0;
	int arr[100] = { 0 };
	cout << "请输入Row Col的值->";//输入行和列
	cin >> Row >> Col;
	cout << "请输入数组的内容->" << endl;
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			cin >> arr[i*Row+j];
		}
	}
	cout << "顺时针打印前的矩阵为：" << endl;
	PrintArr(arr, Row, Col);
	cout << "顺时针打印出来的矩阵为：" << endl;
	PrintMatrix(arr, Row, Col);
	cout << endl;
	system("pause");
	return 0;
}