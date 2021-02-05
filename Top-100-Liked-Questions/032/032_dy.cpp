class Solution {
public:
	int longestValidParentheses(string s) {
		int count = 0, len = 0, i, n = s.length(), ans = 0;
		for (i = 0 ; i < n ; i++)
		{
			if (s[i] == '(')
				++count;
			else
				--count;
			++len;
			if (count < 0)
			{
				count = 0;
				len = 0;
			}
			if (count == 0)
				ans = max(ans, len);
		}
		count = 0;
		len = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == ')') {
				count++;

			}
			else {
				count--;
			}
			++len;
			if (count < 0)
			{
				count = 0;
				len = 0;
			}
			if (count == 0)
				ans = max(ans, len);
		}

		return ans;
	}

};