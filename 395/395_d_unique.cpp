class Solution {
public:
	int longestSubstring(string s, int k) {
		if (k == 1)
			return s.length();
		if (k > s.length())
			return 0;
		int ans = 0, start, end, uni, i, pending, n = s.length(), temp, winuni;
		vector<int> count(26, 0);
		for (i = 0, uni = 0; i < n; i++) //count the number of unique characters
		{
			if (++count[s[i] - 'a'] == 1)
				uni++;
		}
		for (i = 1; i <= uni; i++)
		{
			start = 0; end = 0;
			count = vector<int>(26, 0);
			winuni = 0; pending = 0;
			while (end < n)
			{
				temp = ++count[s[end] - 'a'];
				if (temp == 1) //First encounter
				{
					winuni++;
					pending++;
				}
				else if (temp == k)
					pending--;
				while (winuni > i)
				{
					temp = --count[s[start] - 'a'];
					if (temp == k - 1)
						pending++;
					else if (temp == 0)
					{
						pending--;
						winuni--;
					}
					start++;
				}
				end++;
				if (!pending)
				{
					//if(end-start > ans)
					//printf("ans = %d, i = %d, start = %d%c, end = %d%c | %d\n", end-start, i, start,s[start], end-1,s[end-1], pending);
					ans = max(ans, end - start);
				}
			}
		}
		//cout<<uni;
		return ans;
	}
};