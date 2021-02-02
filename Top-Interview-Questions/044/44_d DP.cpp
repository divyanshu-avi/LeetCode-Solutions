class Solution {
public:
    bool isMatch(string s, string p) {
        int m, n, i, j;
        m = s.size(); n = p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));//initialize all to false
        //dp[i][j] s of length i matches p of length j.
        dp[0][0] = 1; //empty matches with empty
    
        for(j=1;j<=n && p[j-1]=='*';j++)
            dp[0][j] = dp[0][j-1];
            
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?')//1:1 match
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];//* can match 0 or more chracters
                //no need to write else here as already everything was initilised to false
            }
        /*for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
                cout<<dp[i][j]<<' ';
            cout<<'\n';
        }*/
        return dp[m][n];
    }
};