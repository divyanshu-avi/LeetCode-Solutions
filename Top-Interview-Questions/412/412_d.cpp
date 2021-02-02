class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> ans(n);
		string temp;
		for (int i = 1; i <= n; i++)
		{
			temp = "";
			if (i % 3 == 0)
				temp += "Fizz";
			if (i % 5 == 0)
				temp += "Buzz";
			else if (i % 3)
				temp += to_string(i);
			ans[i - 1] = temp;
		}
		return ans;
	}
};