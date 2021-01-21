class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> count(26, 0);
		int left = 0, i, n1 = s.length(), n2 = t.length();
		if (n1 != n2)
			return false;
		for (i = 0; i < n1; i++)
			if (++count[s[i] - 'a'] == 1)
				left++;
		for (i = 0; i < n2; i++)
		{
			//if(temp == 0)//Actually not needed as I have already checked n1==n2
			//left--;
			if (--count[t[i] - 'a'] == -1)
				return false;
		}
		//return left==0; //Here I can simply return true
		return true;
	}
};