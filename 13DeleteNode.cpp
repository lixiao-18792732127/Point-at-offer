 //��O(1)ʱ��ɾ��������
//�������������ͷָ���һ�����ָ�룬����һ������
//��O(1)ʱ��ɾ���ý�㡣
#include<iostream>
using namespace std;
struct ListNode
{
	int _value;
	ListNode* next;
};
void DeleteNode(ListNode** pListHead, ListNode* pToBeDelete)
{
	if (!pListHead || !pToBeDelete)//���ͷ���Ϊ�ջ��߽�Ҫɾ���Ľڵ�Ϊ�գ��ͷ���
	{
		return;
	}
	if (pToBeDelete->next != NULL)
	{
		ListNode* pNext = pToBeDelete->next;
		pToBeDelete->_value = pNext->_value;
		pToBeDelete->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	else if (*pListHead == pToBeDelete)
	{
		delete pToBeDelete;
		pToBeDelete = NULL;
		*pListHead = NULL;
	}
	else
	{
		ListNode* pNode = *pListHead;
		while (pNode->next != pToBeDelete)
		{
			pNode = pNode->next;
		}
		pNode->next = NULL;
		delete pToBeDelete;
		pToBeDelete = NULL;
	}
}
