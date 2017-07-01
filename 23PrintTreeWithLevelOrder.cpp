#include<iostream>
using namespace std;
#include<queue>

struct TreeNode
{
	int _value;
	TreeNode* _left;
	TreeNode* _right;
};

void LevelOrder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	queue<const TreeNode*> q;
	q.push(root);

	while (!q.empty)
	{
		const TreeNode* top = q.front();
		q.pop();

		cout << top->_value << " ";
		if (top->_left != NULL)
		{
			q.push(top->_left);
		}
		if (top->_right != NULL)
		{
			q.push(top->_right);
		}
	}
}
