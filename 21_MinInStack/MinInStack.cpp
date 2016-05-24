#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MIN(a,b) (a)<(b)?(a):(b)

//要用到两个栈，此处将两个栈pair
class Solution{
	public:
		void push(int value)
		{
			s.push(pair<int,int>(value,s.empty()?value:MIN(value,min())));
		}

		void pop(){
			s.pop();
		}

		int top(){
			return s.top().first;
		}

		int min(){
			return s.top().second;
		}
	private:
		stack<pair<int,int> > s;
};

int main()
{
	Solution ex;
	int a[5] = {
		4,2,6,5,1
	};
	for(int i=0;i<5;i++){
		ex.push(a[i]);
	}
	cout<<ex.min()<<endl;
	return 0;
}
