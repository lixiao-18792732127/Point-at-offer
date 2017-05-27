#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

struct ListNode//定义一个链表的结构体
{
	int _data;
	ListNode* _pNext;
};

void InitList(ListNode** phead)//初始化链表为空
{
	*phead = NULL;
}

ListNode* BuyNewNode(int data)//创建一个新的节点
{
	ListNode* newNode = NULL;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = data;
	newNode->_pNext = NULL;
	return newNode;
}

void PushBack(ListNode** phead, int data)
{
	assert(phead);
	ListNode* newNode = BuyNewNode(data);
	if (*phead == NULL)
	{
		*phead = newNode;
		return;
	}

	ListNode* cur = *phead;
	while (cur->_pNext)//如果cur的next不为空的时候
	{
		cur = cur->_pNext;
	}
	cur->_pNext = newNode;
}

void PrintList(ListNode* phead)//正序打印链表
{
	assert(phead);
	ListNode* cur = phead;
	while (cur)
	{
		cout << cur->_data << " ";
		cur = cur->_pNext;
	}
	cout << endl;
}
void ReversePrintList(ListNode* phead)
{
	if (phead == NULL)
	{
		return;
	}
	ReversePrintList(phead->_pNext);
	cout << phead->_data << " ";
}
void ReversePrintListNonR(ListNode* phead)
{
	assert(phead);
	stack<ListNode*>s;
	ListNode* cur = phead;
	while (cur)
	{
		s.push(cur);
		cur = cur->_pNext;
	}
	while (!s.empty())
	{
		cout << s.top()->_data << " ";
		s.pop();
	}
	cout << endl;
}
int main()
{
	ListNode* phead;
	InitList(&phead);
	PushBack(&phead, 1);
	PushBack(&phead, 2);
	PushBack(&phead, 3);
	PushBack(&phead, 4);
	cout << "正序打印链表：";
	PrintList(phead);
	cout << "逆序递归发打印链表：";
	ReversePrintList(phead);
	cout << endl;
	cout << "逆序非递归法打印链表：";
	ReversePrintListNonR(phead);
	system("pause");
	return 0;
}