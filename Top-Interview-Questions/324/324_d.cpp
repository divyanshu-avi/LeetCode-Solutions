class Solution {
public:
	vector<int> ans;

	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = (nums.size() - 1) / 2, i, n = nums.size();
		ans.push_back(nums[mid]);
		for (i = n - 1; i > mid; i--)
		{
			ans.push_back(nums[i]);
			if (mid - n + i >= 0) ans.push_back(nums[mid - n + i]);
		}
		for (i = 0; i < n; i++)
			nums[i] = ans[i];
	}
};