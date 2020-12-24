class Solution {
public
    int lengthOfLongestSubstring(string s) {
        unordered_mapchar, int  m;
        int start=0, end=0, ans = 0;
        while(starts.length() && end  s.length())
        {
            if(endstart)
            {
                end = start;
                continue;
            }
            if(m.find(s[end])!=m.end() && m[s[end]]=start)
                start = m[s[end]] + 1;
            m[s[end]] = end;
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};