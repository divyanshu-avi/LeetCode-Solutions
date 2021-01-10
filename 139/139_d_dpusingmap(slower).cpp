class Solution {
public:
    bool recur(string& s, int pos, unordered_set<string>&  dict, unordered_map<string, bool>& dp)
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
                if(dp.find(s.substr(i+1)) == dp.end())
                    dp.insert({s.substr(i+1), recur(s, i+1, dict, dp)});
                ans = dp[s.substr(i+1)];
            }
        }
        dp.insert({s.substr(pos), ans});
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int i, n = s.length();
        for(i=0;i<wordDict.size();i++)
            dict.insert(wordDict[i]);
        unordered_map<string, bool> dp;
        
        return recur(s, 0, dict, dp);
    }
};