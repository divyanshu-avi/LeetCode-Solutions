class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int i, j, n = nums.size();
		vector<int> dp(n, 1);
		for (i = 1; i < n; i++)
			for (j = 0; j < i; j++)
				if (nums[j] < nums[i])
					dp[i] = max(dp[i], 1 + dp[j]);
		return *max_element(dp.begin(), dp.end());
	}
};