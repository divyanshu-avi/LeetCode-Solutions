class Solution {
public:
	int calculate(string s) {
		stack<int> numst;
		stack<char> opst;
		unordered_map<char, int> priority;
		priority.insert({'+', 0});
		priority.insert({'-', 0});
		priority.insert({'*', 1});
		priority.insert({'/', 1});
		//reverse(s.begin(), s.end());
		//cout<<s;
		int num = 0, num2, i, n = s.length(), start = n - 1, end = n - 1;
		for (i = n - 1; i >= 0; i--)
		{
			if (isdigit(s[i]))
				start = i;
			else if (priority.find(s[i]) != priority.end()) //s[i] is an operator
			{
				num = stoi(s.substr(start, end - start + 1));
				numst.push(num);
				//cout<<"Pushed "<<num<<" onto numst\n";
				while (!opst.empty() && priority[s[i]] < priority[opst.top()])
				{
					num = numst.top();
					numst.pop();
					//cout<<"Popped "<<num<<" from numst\n";
					num2 = numst.top();
					numst.pop();
					//cout<<"Popped "<<num2<<" from numst\n";
					//cout<<"Popped "<<opst.top()<<" from opst\n";
					switch (opst.top())
					{
					case '+' : num = num + num2; break;
					case '-' : num = num - num2; break;
					case '*' : num = num * num2; break;
					case '/' : num = num / num2; break;
					}
					opst.pop();
					numst.push(num);
					//cout<<"Pushed "<<num<<" onto numst\n";
				}
				opst.push(s[i]);
				//cout<<"Pushed "<<s[i]<<" onto opst\n";
				start = end = i - 1;
			}
		}
		num = stoi(s.substr(start, end - start + 1));
		numst.push(num);
		//cout<<"Pushed "<<num<<" onto numst\n";

		while (!opst.empty())
		{
			num = numst.top();
			numst.pop();
			//cout<<"Popped "<<num<<" from numst\n";
			num2 = numst.top();
			numst.pop();
			//cout<<"Popped "<<num2<<" from numst\n";
			//cout<<"Popped "<<opst.top()<<" from opst\n";
			switch (opst.top())
			{
			case '+' : num = num + num2; break;
			case '-' : num = num - num2; break;
			case '*' : num = num * num2; break;
			case '/' : num = num / num2; break;
			}
			opst.pop();
			numst.push(num);
			//cout<<"Pushed "<<num<<" onto numst\n";
		}
		return numst.top();
	}
};