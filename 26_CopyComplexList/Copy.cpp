#include <iostream>
using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next,*random;
	RandomListNode(int data):label(data),next(NULL),random(NULL){}
};

RandomListNode* Clone(RandomListNode* pHead)		
{
	if(!pHead)
		return NULL;
	//复制第一步：先复制节点插入每一个相应节点的后面
    RandomListNode *cur = pHead;
    while(cur){
        RandomListNode *tmp = new RandomListNode(cur->label);
        tmp->next = cur->next;
        cur->next = tmp;
        cur = tmp->next;
    }
    //修改random指向
    cur = pHead;
    while(cur){
	    RandomListNode *tmp = cur->next;
        if(cur->random){
            tmp->random = cur->random->next;
        }
        cur = tmp->next;
    }
    //将链表拆分成两条链表
    cur = pHead;
    RandomListNode *Head = pHead->next;
    RandomListNode *Node = NULL;
    while(cur->next){//节点挨个处理
	    Node = cur->next;		
        cur->next = Node->next;								
        cur = Node;
    }								
    return Head;
}

int main()
{
	
	return 0;
}
