class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> count;
		if (nums1.size() < nums2.size())
			swap(nums1, nums2);
		int i, n1 = nums1.size(), n2 = nums2.size();
		for (i = 0; i < n1; i++)
			count[nums1[i]]++;
		vector<int> ans;
		for (i = 0; i < n2; i++)
		{
			if (count[nums2[i]] > 0)
			{
				ans.push_back(nums2[i]);
				count[nums2[i]]--;
			}
		}
		return ans;
	}
};