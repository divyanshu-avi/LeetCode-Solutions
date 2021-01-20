class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int i, n = nums.size(), prefix = 1, suffix = 1;
		vector<int> ans(n, 1);
		for (i = 0; i < n; i++)
		{
			ans[i] *= prefix;
			ans[n - i - 1] *= suffix;
			prefix *= nums[i];
			suffix *= nums[n - 1 - i];
		}
		return ans;
	}
};