void Mirror(TreeNOde *pRoot)
{
	if(pRoot == NULL)
		return;

	TreeNOde *tmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = tmp;

	Mirror(pRoot->left);
	Mirror(pRoot->right);
}
