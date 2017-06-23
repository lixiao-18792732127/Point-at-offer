//����������������������ϲ�����������ʹ������
//�еĽڵ���Ȼ�ǰ��յ����������
#include<iostream>
using namespace std;

struct ListNode
{
	int _value;
	ListNode* _next;
};
ListNode* MergeList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
	{
		return pHead2;
	}
	else if (pHead2 == NULL)
	{
		return pHead1;
	}
	ListNode* pMergeHead = NULL;
	if (pHead1->_value < pHead2->_value)
	{
		pMergeHead = pHead1;
		pMergeHead->_next = MergeList(pHead1->_next, pHead2);
	}
	else
	{
		pMergeHead = pHead2;
		pMergeHead->_next = MergeList(pHead1, pHead2->_next);
	}
	return;
}