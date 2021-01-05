class Solution {
public:
    
    int numDecodings(string s) {
        int n = s.length(), sum, i;
        vector<int> dp(n+1, 0);//dp[i] means no. of ways in which mesage from index i to last can  be decoded
        
        dp[n] = 1;//Needed for validity
        dp[n-1] = s[n-1]=='0' ? 0 : 1;
        for(i=n-2; i>=0;i--)
        {
            if(s[i] == '0')
                dp[i] = 0;
            else
            {
                dp[i] += dp[i+1];
                sum = (s[i]-'0')*10 + (s[i+1]-'0');
                if(sum<=26)
                    dp[i] += dp[i+2];
            }
            //If 2 simultaneous answers are 0 that means one of them is 0 and we can't decode it.
            if(dp[i] == 0 && dp[i+1] == 0)
                return 0;
        }
        return dp[0];
    }
};