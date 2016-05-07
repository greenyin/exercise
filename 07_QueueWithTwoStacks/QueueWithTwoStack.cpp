class Solution
{
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
