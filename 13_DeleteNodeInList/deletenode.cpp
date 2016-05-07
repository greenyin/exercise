#include <iostream>
using namespace std;

/*
 *struct ListNode{
      int val;
	  ListNode *next;
 };
 * */

void DeleteNode(ListNode *&pHead,ListNode *pnode)
{
	if(pHead == NULL || pnode == NULL)
		return;
	if(pnode->next != NULL){
	    ListNode *pnext = pnode->next;
	    pnode->val = pnext->val;
	    pnode->next = pnext->next;
	    delete pnext;
        pnext = NULL;
	}else if(pHead = pnode){
		delete pnode;
		pnode = NULL;
		pHead = NULL;
	}else{
		ListNode *p = pHead;
		while(p->next != pnode){
			p = p->next;
		}
		p->next = NULL;
		delete pnode;
		pnode = NULL;
	}
}

int main()
{
	return 0;
}
