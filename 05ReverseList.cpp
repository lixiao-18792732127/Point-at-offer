#include<iostream>
using namespace std;
#include<assert.h>
#include<stack>

struct ListNode//����һ������Ľṹ��
{
	int _data;
	ListNode* _pNext;
};

void InitList(ListNode** phead)//��ʼ������Ϊ��
{
	*phead = NULL;
}

ListNode* BuyNewNode(int data)//����һ���µĽڵ�
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
	while (cur->_pNext)//���cur��next��Ϊ�յ�ʱ��
	{
		cur = cur->_pNext;
	}
	cur->_pNext = newNode;
}

void PrintList(ListNode* phead)//�����ӡ����
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
	cout << "�����ӡ����";
	PrintList(phead);
	cout << "����ݹ鷢��ӡ����";
	ReversePrintList(phead);
	cout << endl;
	cout << "����ǵݹ鷨��ӡ����";
	ReversePrintListNonR(phead);
	system("pause");
	return 0;
}