class Solution {
public:
    bool recur(string& s, int pos, unordered_set<string>&  dict, vector<int>& dp)
    {
        bool ans = false;
        string temp = "";
        int i, n = s.length();
        if(pos==n)
            ans = true;
        for(i = pos; i<n && !ans; i++)
        {
            temp += s[i];
            if(dict.find(temp)!=dict.end())
            {
                if(dp[i+1] == -1)
                    dp[i+1] = recur(s, i+1, dict, dp);
                ans = dp[i+1];
            }
        }
        dp[pos] = ans;
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int i, n = s.length();
        for(i=0;i<wordDict.size();i++)
            dict.insert(wordDict[i]);
        vector<int> dp(n+1, -1);//dp[i] means whether we can break the substring from ith index to the end.
        
        return recur(s, 0, dict, dp);
    }
};