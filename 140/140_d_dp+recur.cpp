class Solution {
public:
    
    bool recur(string& s, int pos, string temp, unordered_set<string>& dict, vector<bool>& dp, vector<string>& ans)
    {
        int i, n = s.length();
        if(pos==n)
        {
            ans.push_back(temp);
            return true;
        }
        bool ok = false;
        //If first word, don't add apce
        string space = "", t2 = "";
        if(pos!=0) space = " ";
        for(i=pos;i<n;i++)
        {
            t2 += s[i];
            //cout<<t2<<' ';
            if(dict.find(t2) != dict.end() && dp[i+1])
            {
                //cout<<temp+space+t2<<'\n';
                ok = recur(s, i+1, temp + space + t2, dict, dp, ans) || ok;
            }
        }
        if(!ok)
            dp[pos] = false;
        return ok;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        int n = s.length(), i;
        vector<bool> dp(n+1, 1);
        unordered_set<string> dict;
        n = wordDict.size();
        for(i=0;i<n;i++)
            dict.insert(wordDict[i]);
        recur(s, 0, "", dict, dp, ans);
        return ans;
    }
};