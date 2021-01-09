class Solution {
public:
    void func(string s, vector<vector<string>> &ans, vector<string> &temp, int start, int len, vector<vector<bool>> &dp){
        if(start>=s.length()){
            ans.push_back(temp);
            return ;
        }
        while(start+len<=s.length()){
            string x=s.substr(start, len);
            if(s[start]==s[start+len-1] && (len-1<2 || dp[start+1][start+len-2])){
                dp[start][start+len-1]=1;
                temp.push_back(x);
                func(s, ans, temp, start+len, 1, dp);
                temp.pop_back();
            }
            len++;
        }
        return ;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(),0));
        func(s, ans, temp,  0, 1, dp);
        return ans;
    }
};
