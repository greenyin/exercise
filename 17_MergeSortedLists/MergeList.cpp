
//recursion
ListNode* MergeSortedLists(ListNode* phead1,ListNode* phead2)
{
	if(phead1 == NULL && phead2 == NULL)
		return NULL;
	if(phead1 == NULL)
		return phead2;
	if(phead2 == NULL)
		return phead1;
	ListNode* newhead;
	if(*phead1 < *phead2){
		newhead = phead1;
		newhead->next = MergeSortedLists(phead1->next,phead2);
	}else{
		newhead = phead2;
		newhead->next = MergeSortedLists(phead1,phead2->next);
	}
	return newhead;
}
