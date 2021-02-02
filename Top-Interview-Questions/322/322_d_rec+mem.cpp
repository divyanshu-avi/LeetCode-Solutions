class Solution {
public:
	vector<int> dp;

	int recur(vector<int>& coins, int amt)
	{
		//cout<<amt<<' ';
		if (dp[amt] != -1)
			return dp[amt];
		int i, n = coins.size(), temp;
		for (i = 0 ; i < n && coins[i] <= amt ; i++)
		{
			temp = recur(coins, amt - coins[i]);
			if (temp == -2)
				continue;
			if (dp[amt] == -1)
				dp[amt] = 1 + temp;
			else
				dp[amt] = min(dp[amt], 1 + temp);
		}
		if (dp[amt] == -1)
			dp[amt] = -2;
		return dp[amt];
	}

	int coinChange(vector<int>& coins, int amount) {
		sort(coins.begin(), coins.end());
		dp.resize(amount + 1, -1);
		dp[0] = 0;
		int temp = recur(coins, amount);
		return max(temp, -1);
	}
};