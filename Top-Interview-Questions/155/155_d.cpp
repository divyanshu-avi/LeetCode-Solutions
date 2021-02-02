class MinStack {
public:
	/** initialize your data structure here. */
	stack<int> norm, mini;

	MinStack() {
		while (!mini.empty())
			mini.pop();
		while (!norm.empty())
			norm.pop();
	}

	void push(int x) {
		norm.push(x);
		if (mini.empty() || x <= mini.top()) //The = in <= is VERY IMPORTANT
			mini.push(x);
	}

	void pop() {
		if (mini.top() == norm.top())
			mini.pop();
		norm.pop();
	}

	int top() {
		return norm.top();
	}

	int getMin() {
		return mini.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */