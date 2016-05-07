#include <iostream>
using namespace std;

/**
 *struct ListNode{
     int val;
	 ListNode *next;
 };
 */

//pay attention to k > length
ListNode* FIndKthNodeFromTail(ListNode* pHead,unsigned int k)
{
	if(pHead == NULL || k == 0)
		return NULL;

	ListNode *pAhead = pHead;
	ListNode *pBehind = NULL;

	for(unsigned int i=0;i<k-1;i++){
		if(pAhead->next != NULL)
			pAhead = pAhead->next;
		else{
			return NULL;
		}
	}

	pBehind = pHead;
	while(pAhead->next != NULL){
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}
	return pBehind;
}
