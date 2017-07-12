//排成升序的，找出前k个
//#include<iostream>
//using namespace std;
//
//int PartSort(int *arr, int left, int right)//找到中间位置
//{
//	while (left<right)
//	{
//		while (left<right&&arr[left] <= arr[right])
//		{
//			left++;
//		}
//		while (left<right&&arr[right] >= arr[left])
//		{
//			right--;
//		}
//		std::swap(arr[left], arr[right]);
//	}
//	return left;
//}
//
//void QuickSort(int* arr, int left, int right)
//{
//	if (left < right)
//	{
//		int mid = PartSort(arr, left, right);
//		QuickSort(arr, left, mid - 1);
//		QuickSort(arr, mid + 1, right);
//	}
//}
//void PrintMinNum(int* arr, size_t n)
//{
//	cout << "最小的" << n << "个数是" << endl;
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void TestFind()
//{
//	int arr[] = { 0, 5, 6, 7, 2, 8, 3, 8, 1 };
//	QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
//	PrintMinNum(arr, 3);
//}
//
//
//int main()
//{
//	TestFind();
//	system("pause");
//	return 0;
//}

//利用快速排序的方法
//#include<iostream>
//using namespace std;

//int PartSort(int *arr, int left, int right)//找到中间位置
//{
//	while (left<right)
//	{
//		while (left<right&&arr[left] <= arr[right])
//		{
//			left++;
//		}
//		while (left<right&&arr[right] >= arr[left])
//		{
//			right--;
//		}
//		std::swap(arr[left], arr[right]);
//	}
//	return left;
//}
//
//void FindMinKNum(int* arr, int left, int right, int index)//快速排序法
//{
//	if (left < right)
//	{
//		int mid = PartSort(arr, left, right);
//		if (mid == (index - 1))
//		{
//			return;
//		}
//		else if (mid>(index - 1))
//		{
//			return FindMinKNum(arr, left, mid-1, index);
//		}
//		else
//		{
//			return FindMinKNum(arr, mid+1, right, index);
//		}
//	}
//}
//void PrintMinNum(int* arr, size_t n)
//{
//	cout << "最小的" << n << "个数是" << endl;
//	for (size_t i = 0; i < n; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//void TestFind()
//{
//	int arr[] = { 2, 5, 6, 7, 2, 8, 3, 8, 1 };
//	FindMinKNum(arr, 0, sizeof(arr) / sizeof(arr[0])-1,3);
//	PrintMinNum(arr, 3);
//}
//
//
//int main()
//{
//	TestFind();
//	system("pause");
//	return 0;
//}

//使用红黑树的方法
#include<iostream>
using namespace std;
#include<set>
struct greater
{
	bool operator()(const int& i1, const int& i2)
	{
		return i1 > i2;
	}
};

pair<bool, multiset<int, greater>>FindMinNum(int* arr,size_t n, int index)
{
	if (index < 1)
	{
		return pair<bool, multiset<int, greater>>(false, multiset<int, greater>());
	}
	multiset<int, greater> Sset;
	for (size_t i = 0; i < n; ++i)
	{
		if (Sset.size() < index)
		{
			Sset.insert(arr[i]);
		}
		else
		{
			if (arr[i] < *Sset.begin())
			{
				Sset.erase(Sset.begin());
				Sset.insert(arr[i]);
			}
		}
	}
	if (Sset.size() < index)
	{
		return pair<bool, multiset<int, greater>>(false, Sset);
	}
	return pair<bool, multiset<int, greater>>(true, Sset);
}

void TestFind()
{
	int arr[] = { 1, 4, 3, 7, 8, 2, 9 };
	int n = 0;
	cout << "请输入k的值->" << endl;
	cin >> n;
	pair<bool, multiset<int, greater>> ret = FindMinNum(arr, sizeof(arr) / sizeof(arr[0]),n);
	cout << "最小的"<<n<<"个数为：" << endl;
	if (ret.first)
	{
		multiset<int, greater>::iterator it = ret.second.begin();
		while (it != ret.second.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	else
	{
		cout << "数组出错了" << endl;
	}
}

int main()
{
	TestFind();
	system("pause");
	return 0;
}