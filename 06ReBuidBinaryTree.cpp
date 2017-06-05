#include<iostream>
using namespace std;
#include<assert.h>


struct TreeNode//定义一个树的结构体
{
	int value;//定义树的值

	TreeNode* left;//定义树的左孩子
	TreeNode* right;//定义树的右孩子
	TreeNode(int data)
		:value(data)
		, left(NULL)
		, right(NULL)
	{
	}
};

typedef TreeNode Node;

Node* ReConstruct(int *preorder, int *inorder, int length)
{
	assert(preorder);
	assert(inorder);

	if (length <= 0)
	{
		return NULL;
	}

	Node* root = new Node(*preorder);
	int* pre_tmp = preorder;
	int* in_tmp = inorder;
	int leftTreeNum = 0;
	int len = length;

	while (*in_tmp != *preorder)
	{
		leftTreeNum++;
		in_tmp++;
		pre_tmp++;
		len--;

		if (len == 1 && *in_tmp != *preorder)
		{
			throw string("前序遍历和中序遍历异常！");
		}
	}

	int* leftPreOrder = preorder + 1;
	int* rightPreOrder = pre_tmp + 1;
	int* leftOrder = inorder;
	int* rightOrder = in_tmp + 1;
	int rightTreeNum = length - leftTreeNum - 1;

	root->left=ReConstruct(leftPreOrder, leftOrder, leftTreeNum);
	root->right = ReConstruct(rightPreOrder, rightOrder, rightTreeNum);

	return root;
}

void InOrderPrint(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	InOrderPrint(root->left);
	cout << root->value << " ";
	InOrderPrint(root->right);
}

void Test()
{
	const int M = 10;
	const int PreOrder[M] = { 1, 2, 4, 8, 9, 5, 10, 3, 6, 7 };
	const int InOrder[M] = { 8, 4, 9, 2, 5, 10, 1, 6, 3, 7 };

	int* preorder = const_cast<int*>(PreOrder);
	int* inorder = const_cast<int*>(InOrder);
	Node* root = ReConstruct(preorder, inorder, M);
	InOrderPrint(root);
	cout << endl;
}
int main()
{
	Test();
	system("pause");
	return 0;
}