#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

vector<vector<int> > res;
vector<int> tmp;

void Find(TreeNode* cur,int sum)
{
	tmp.push_back(cur->val);
	//如果节点总和等于sum，而又是叶子节点的话，将这个序列放到res中
	if(sum-cur->val==0 && !cur->left && !cur->right){
		res.push_back(tmp);
	}else{
		if(cur->left){//如果左子树存在，递归
			Find(cur->left,sum-cur->val);
		}
		if(cur->right){//
			Find(cur->right,sum-cur->val);
		}
	}
	tmp.pop_back();//如果不满足要求，把节点pop出来，然后尝试新的节点
}

vector<vector<int> > FindPath(TreeNode* root,int number)
{
	if(root == NULL)
		return res;
	Find(root,number);
	return res;
}

int main()
{
	return 0;
}
