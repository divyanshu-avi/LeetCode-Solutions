class Solution {
public:
    string longestPalindrome(string s) {
        string ans="";
        int i, odd, even, len;
        for(i=0;i<s.length();i++)
        {
            odd = palindromelen(s, i, i);
            even = palindromelen(s, i, i+1);
            len = max(odd, even);
            if(len>ans.length())
            {
                cout<<len<<'|'<<i<<',';
                ans = s.substr(i - (len+1)/2 + 1, len);
            }
        }
        return ans;
    }
    int palindromelen(string s, int left, int right)
    {
        int len=0;
        if(left == right)
        {
            len = 1;
            left--;
            right++;
        }
        while(left>=0 && right<s.length() && s[left] == s[right])
        {
            len+=2;
            left--;
            right++;
        }
        return len;
    }
};