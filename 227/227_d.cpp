class Solution {
public:

	int rev(int n)
	{
		int ans = 0;
		while (n)
		{
			ans *= 10;
			ans += n % 10;
			n /= 10;
		}
		return ans;
	}

	int calculate(string s) {
		stack<int> numst;
		stack<char> opst;
		unordered_map<char, int> priority;
		priority.insert({'+', 0});
		priority.insert({'-', 0});
		priority.insert({'*', 1});
		priority.insert({'/', 1});
		reverse(s.begin(), s.end());
		//cout<<s;
		int num = 0, num2, i, n = s.length(), start = 0, end = 0;
		char op;
		for (i = 0; i < n; i++)
		{
			if (isdigit(s[i]))
				end = i;
			else if (priority.find(s[i]) != priority.end()) //s[i] is an operator
			{
				string temp = s.substr(start, end - start + 1);
				reverse(temp.begin(), temp.end());
				num = stoi(temp);
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
				start = end = i + 1;
			}
		}
		string temp = s.substr(start, end - start + 1);
		reverse(temp.begin(), temp.end());
		num = stoi(temp);
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