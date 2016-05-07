bool HasSubTree(TreeNode* pRoot1,TreeNode* pRoot2)
{
	bool result = false;
	if(pRoot1 != NULL && pRoot2 != NULL){
		if(pRoot1->val == pRoot2->val){
			result = DoesTree1HasTree2(pRoot1,pRoot2);
		}
		if(!result){
			result = HasSubTree(pRoot1->leftChild,pRoot2);
		}
		if(!result){
			result = HasSubTree(pRoot2->rightChild,pRoot2);
		}
	}
	return result;
}

bool DoesTree1HasTree2(TreeNode* pRoot1,TreeNode* pRoot2)
{
	if(pRoot1 == NULL)
		return false;
	if(pRoot2 == NULL)
		return true;

	if(pRoot1->val != pRoot2->val){
       return false;
	}
	if(pRoot1->val == pRoot2->val){
		return DoesTree1HasTree2(pRoot1->leftChild,pRoot2->leftChild) &&
			DoesTree1HasTree2(pRoot1->rightChild,pRoot2->rightChild);
	}
}
