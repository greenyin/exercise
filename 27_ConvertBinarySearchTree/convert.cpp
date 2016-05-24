#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//method 1
TreeNode* ReConvert(TreeNode* Root)
{//从下到上处理节点
	if(!Root)
		return Root;
	if(Root->left){
		TreeNode *left = ReConvert(Root->left);
		while(left->right){
			left = left->right;
		}
		left->right = Root;
		Root->left = left;
	}
	if(Root->right){
		TreeNode *right = ReConvert(Root->right);
		while(right->left){
			right = right->left;
		}
		right->left = Root;
		Root->right = right;
	}
	return Root;
}

TreeNode* Convert(TreeNode* Root)
{
	if(!Root)
		return NULL;
	Root = ReConvert(Root);
	while(Root->left){
		Root = Root->left;
	}
	return Root;
}


//methond 2
//定义两个全局变量
TreeNode *head,*cur;
//利用中序访问来把搜索二叉树转化成双向链表
void InOrder(TreeNode* r)
{
	if(r){
		InOrder(r->left);//先处理左子树
		if(head==NULL){//再处理根节点
			cur = r;
			head = r;
		}else{
			cur->right = r;
			r->left = cur;
			cur = r;
		}
		InOrder(r->right);//最后处理右子树
	}
}

TreeNode* Convert(TreeNode* Root)
{
	head = NULL;
	cur = NULL;
	InOrder(Root);
	return head;
}
int main()
{
	return 0;
}
