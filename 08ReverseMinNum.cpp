#define _CRT_SECURE_NO_DEPRECATE
#include<tchar.h>
#include<iostream>
using namespace std;

int BinarySearchMinNum(int* arr, int length)
{
	if (arr != NULL && length > 0)
	{
		int low = 0;
		int high = length - 1;
		int mid = low;

		while (arr[low] >= arr[high])
		{
			if (high - low == 1)
			{
				mid = high;
				break;
			}

			mid = low + ((high - low) >> 1);
			if (arr[low] == arr[high] && arr[low] == arr[mid])
			{
				int min = arr[low];
				for (int i = low + 1; i <= high; i++)
				{
					if (min > arr[i])
					{
						min = arr[i];
					}
				}
				return min;
			}
			if (arr[mid] >= arr[low])
			{
				low = mid;
			}
			else if (arr[mid] <= arr[high])
			{
				high = mid;
			}
		}
		return arr[mid];
	}
	else
	{
		cout << "Êý×éÎª¿Õ£¡" << endl;
		return -1;
	}
}

int main()
{
	int arr1[5] = { 3, 4, 5, 1, 2 };
	cout << BinarySearchMinNum(arr1, 5) << endl;
	system("pause");
	return 0;
}