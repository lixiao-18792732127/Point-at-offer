#include<iostream>
using namespace std;
bool IsBST(int arr[], int length)
{
	if (arr == NULL || length < 0)
	{
		return false;
	}
	int root = arr[length - 1];
	int i = 0;
	for (i = 0; i < length - 1; ++i)
	{
		if (arr[i]>root)
		{
			break;
		}
	}
	int j = i;
	for (j=i;j<length-1;++j)
	{
		if (arr[j] < root)
		{
			return false;
		}
	}

	bool IsBst_left = true;
	if (i>0)
	{
		IsBst_left = IsBST(arr, i);
	}

	bool IsBST_right = true;
	if (j < length - 1)
	{
		IsBST_right = IsBST(arr + i, length - i - 1);
	}
	return(IsBst_left && IsBST_right);
}

int main()
{
	int arr[] = { 5, 7, 6, 9, 11, 10, 8 };
	//int arr[] = { 7, 4, 6, 5 };
	int ret = 0;
	ret = IsBST(arr, sizeof(arr) / sizeof(arr[0]));
	if (ret == 0)
	{
		cout << "该数组序列不是一颗二叉树！" << endl;
	}
	if (ret == 1)
	{
		cout << "该数组序列是一颗二叉树！" << endl;
	}
	system("pause");
	return 0;
}