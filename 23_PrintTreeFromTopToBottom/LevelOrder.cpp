#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<int> PrintTree(TreeNode *root)
{
	vector<int> result;
	if(root == NULL)
		return result;
	queue<TreeNode*> que;
	que.push(root);
	TreeNode *tmp;
	while(!que.empty()){
		tmp = que.front();
		que.pop();
		result.push_back(tmp->val);
		if(tmp->left)
			que.push(tmp->left);
		if(tmp->right)
			que.push(tmp->right);
	}
	return result;
}

int main()
{
	return 0;
}
