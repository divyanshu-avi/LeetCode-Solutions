class Solution {
public:
	int binary_search(vector<int>& ans, int target)
	{
		int lo = 0, hi = ans.size() - 1, mid;
		while (lo < hi)
		{
			mid = lo + (hi - lo) / 2;
			if (ans[mid] == target)
				return mid;
			else if (ans[mid] < target)
				lo = mid + 1;
			else
				hi = mid;
		}
		return hi;
	}

	int lengthOfLIS(vector<int>& nums) {
		vector<int> ans;
		int i, n = nums.size();
		for (i = 0; i < n; i++)
		{
			if (ans.empty() || nums[i] > ans.back())
				ans.push_back(nums[i]);
			else
				ans[binary_search(ans, nums[i])] = nums[i];
		}
		return ans.size();
	}
};