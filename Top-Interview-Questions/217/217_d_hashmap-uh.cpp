class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> hashset;
		int i, n = nums.size();

		for (i = 0; i < n; i++)
		{
			if (hashset.find(nums[i]) != hashset.end())
				return true;
			hashset.insert(nums[i]);
		}
		return false;
	}
};