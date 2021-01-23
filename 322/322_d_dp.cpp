class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int i, j, n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (i = 1; i <= amount; i++)
        {
            for (j = 0; j < n && coins[j] <= i; j++)
            {
                if (dp[i - coins[j]] == -1)
                    continue;
                if (dp[i] == -1)
                    dp[i] = 1 + dp[i - coins[j]];
                else
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
        return dp[amount];
    }
};