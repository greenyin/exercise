//recursion
void Mirror(TreeNode *pRoot)
{
	if(pRoot == NULL)
		return;
	if(pRoot->left == NULL && pRoot->right == NULL)
		return;

	TreeNode *tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	if(pRoot->left)
	    Mirror(pRoot->left);
	if(pRoot->right)
	    Mirror(pRoot->right);
}

//circulation (xun huan)
void Mirror2(TreeNode *pRoot)
{
	if(pRoot == NULL)
		return;
	if(pRoot->left == NULL && pRoot->right == NULL)
		return;
	std::stack<TreeNode*> st;
	st.push(pRoot);

	while(st.size()){
		TreeNode* root = st.top();
		st.pop();
		if(root->left != NULL || root->right != NULL){
			TreeNode *tmp = root->left;
			root->left = root->right;
			root->right = tmp;
		}

		if(!root->left)
			st.push(root->left);
		if(!root->right)
			st.push(root->right);
	}
}
