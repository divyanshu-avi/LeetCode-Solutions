class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        int i, j;
        for(i=1;i<m;i++)
            for(j=1;j<n;j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];//We can reach the current block either from the top or from the left.
        return dp[m-1][n-1];
    }
};