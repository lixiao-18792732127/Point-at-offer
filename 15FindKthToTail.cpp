#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
using namespace std;
#include<stack>
struct  ListNode
{
	int value;
	ListNode* next;
};

ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
	if (pListHead == NULL || k == 0)//��ͷ���Ϊ�ջ���k����0ʱ
	{
		return NULL;//ֱ�ӷ���
	}
	ListNode *pHead1 = pListHead;//�����һ��ָ�����ͷ�ڵ�
	ListNode *pHead2 = NULL;//����ڶ���ָ��Ϊ��
	for (unsigned int i = 0; i < k - 1; i++)
	{
		if (pHead1->next != NULL)//��һ��ָ�����һ����Ϊ�յ�ʱ������ߣ�ֱ��k-1��λ��
		{
			pHead1 = pHead1->next;
		}
		else
		{
			return NULL;
		}
	}
	//��pHead1�ߵ���k-1λ��ʱ���ڶ���ָ�뿪ʼ�����
	pHead2 = pListHead;//�ڶ���ָ�����ͷ�ڵ�
	while (pHead1->next != NULL)
	{//����ָ�붼����ߣ���һ��ָ���ߵ����ʱ���ڶ���ָ��պþ��ǵ�����K�Ľڵ�
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return pHead2;
}