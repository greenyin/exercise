#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
public:
	MyQueue(stack<int> s1,stack<int> s2):stack1(s1),stack2(s2){}
public:
	void push(int node){
		stack1.push(node);
	}

	int pop()
	{
		while(!stack1.empty()){
			int data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}

		int val = stack2.top();
		stack2.pop();
		while(!stack2.empty()){
			int data = stack2.top();
			stack2.pop();
			stack1.push(data);
		}
		return val;
	}
private:
	stack<int> stack1;
	stack<int> stack2;
};

int main()
{
	stack<int> s1;
	stack<int> s2;
	MyQueue q(s1,s2);
	q.push();
	q.pop();
}
