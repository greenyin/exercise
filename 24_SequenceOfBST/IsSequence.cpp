#include <iostream>
#include <vector>
using namespace std;

bool Sequence(vector<int> v,int start,int end)
{
	if(end - start <= 0)//如果end和start指向同一个元素，则返回true
		return true;
	int i = end;//从后向前操作
	while(i>start && v[i-1] > v[end])//如果大于根节点，继续向前移动
		--i;
	for(int j = i-1;j>=0;--j){
		if(v[j] > v[end])//如果此时还有元素大于根节点，直接返回false
			return false;
	}
	//将序列分成两部分，然后递归
	return Sequence(v,start,i-1) && Sequence(v,i,end-1);
}

bool IsSequenceOfBST(vector<int> v)
{
	int size = v.size();
	if(size == 0)
		return false;
	return Sequence(v,0,size-1);
}

int main()
{
	vector<int> r;
	r.push_back(1);
	r.push_back(2);
	r.push_back(4);
	r.push_back(5);
	r.push_back(3);
	cout<<IsSequenceOfBST(r)<<endl;
	return 0;
}
