class Solution {
public:
    bool isPalindrome(int start, int end, string& s)
    {
        while(start<end)
        {
            if(s[start] != s[end])
                break;
            start++; end--;
        }
        return start>=end;
    }
    
    void recur(string s, int partition, vector<string>& temp, vector<vector<string>>& ans, vector<vector<int>>& dp)
    {
        if(partition == s.length())
        {
            ans.push_back(temp);
            return;
        }
        int i;
        for(i=partition ; i<s.length() ; i++)
        {
            if(dp[partition][i] == -1)
                dp[partition][i] = isPalindrome(partition, i, s);
            
            if(dp[partition][i])
            {
                temp.push_back(s.substr(partition, i-partition+1));
                recur(s, i+1, temp, ans, dp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        recur(s, 0, temp, ans, dp);
        
        return ans;
    }
};