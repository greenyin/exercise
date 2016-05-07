ListNode* ReverseList(ListNode* pHead)
{
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;

	ListNode *ReverseHead = NULL;
	while(pNode){
		ListNode *pNext = pNode->next;
		if(pNext == NULL)
			ReverseHead = pNode;
		
		pNode->next = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}

	return ReverseHead;
}

//recursion
ListNode* ReverseList(ListNode* pHead)
{
	return NULL;
}
