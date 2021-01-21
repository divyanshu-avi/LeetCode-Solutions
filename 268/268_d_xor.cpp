class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int jor = 0, i, n = nums.size();
		for (i = 0; i <= n; i++)
			jor ^= i;
		for (i = 0; i < n; i++)
			jor ^= nums[i];
		return jor;
	}
};