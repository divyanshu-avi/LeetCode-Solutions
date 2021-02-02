class Solution {
public:

	int solve(int N, int K, vector<vector<int>>& dp)
	{
		if (dp[N][K] != -1)
			return dp[N][K];
		if (N <= 2) //for N = 1 and 2 number of eggs don't matter (as long as you have atleast 1 egg).
			return N;
		int i, temp, mid, low = 1, hi = N, mini = INT_MAX, left, right;
		while (low <= hi)
		{
			mid = low + (hi - low) / 2;
			left = solve(mid - 1, K, dp);
			right = solve(N - mid, K - 1, dp);
			temp = left - right;
			mini = min(mini, max(left, right));
			if (temp == 0)
				break;
			else if (temp > 0)
				hi = mid - 1;
			else
				low = mid + 1;
		}
		dp[N][K] = 1 + mini;
		return 1 + mini;
	}

	int superEggDrop(int K, int N) {
		vector<vector<int>> dp(N + 1, vector<int>(K + 1, -1));
		int i;
		for (i = 0; i <= N; i++)
			dp[i][1] = i;

		return solve(N, K, dp);
	}
};