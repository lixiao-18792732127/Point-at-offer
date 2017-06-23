#include<iostream>
using namespace std;

struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
};

bool DoesTree1HaveTree2(BinaryTreeNode* Root1, BinaryTreeNode* Root2)
{
	if (Root2 == NULL)//����2Ϊ�յ�ʱ���У�������ȷ����Ϊ����Ҳ��һ����������
	{
		return true;
	}
	if (Root1 == NULL)//�������1Ϊ�գ��򷵻ش����κ��������ǿ���������
	{
		return false;
	}
	if (Root1->_value != Root2->_value)//���Root1��ֵ��Root2��ֵ����ȣ�����false
	{
		return false;
	}
	return DoesTree1HaveTree2(Root1->_left, Root2->_left) && DoesTree1HaveTree2(Root1->_right, Root2->_right);//Ȼ�󷵻�Root1��Root2����������������
}