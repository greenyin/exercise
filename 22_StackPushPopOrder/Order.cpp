#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//
bool IsPopOrder(const int* pPush,const int* pPop,int nlength)
{
	bool possible = false;

	if(pPush != NULL && pPop != NULL && nlength!=0)
	{
		const int* pNextPush = pPush;
		const int* pNextPop = pPop;

		stack<int> stackData;

		while(pNextPop - pPop < nlength){
			while(stackData.empty() || stackData.top() != *pNextPop){
				if(stackData.size() == nlength)//这种是元素按照顺序统一入栈的情况
					break;
				stackData.push(*pNextPush);//第一个出栈元素之前的元素统一入栈
				pNextPush++;
			}

			if(stackData.top() != *pNextPop)//如果栈顶元素与出栈序列的front元素不同，直接跳出循环
				break;

			stackData.pop();
			pNextPop++;
		}
		if(stackData.empty() && pNextPop-pPop == nlength)
			possible = true;
	}
	return possible;
}

//用vector模拟stack来用
bool IsPopOrder_(const int *pPush,const int* pPop,int length)
{
	if(pPush == NULL || pPop == NULL)
		return false;
	vector<int> stack;
	int i = 0,j = 0;
	for(;i<length;++i){
		stack.push_back(pPush[i]);//当i标识的元素与出栈序列的元素不同时就一直入栈
		while(j<length && stack.back() == pPop[j])//一旦相同，就出栈，j++
		{
			stack.pop_back();
			j++;
		}
	}
	return stack.empty();
}

int main()
{
	int a[5] = {
		1,2,3,4,5
	};
	int b[5] = {
		5,4,3,2,1
	};
	cout<<IsPopOrder(a,b,5)<<endl;
	cout<<IsPopOrder_(a,b,5)<<endl;
	return 0;
}
