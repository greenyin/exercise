#include <iostream>
#include <stack>
using namespace std;

struct ListNode{
	int val;
	struct ListNOde *next;
	ListNode(int x):val(x),next(NULL){}
};

void PrintReversed(ListNode* pHead)
{
	stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	
	while(pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty()){
		pNode = nodes.top();
		cout<<pNode->val<<"\t";
		nodes.pop();
	}
	cout<<endl;
}

void PrintReversed_Recursion(ListNode* pHead)
{
	if(pHead != NULL){
		if(pHead->next != NULL){
			PrintReversed_Recursion(pHead->next);
		}

		cout<<pHead->val<<"\t";
	}
}

int main()
{
	return 0;
}
