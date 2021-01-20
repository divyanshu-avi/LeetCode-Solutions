class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (k == 1) return nums;
		vector<int> ans;
		deque<int> dll;//doubly linked list (fast insertion and deletion from both ends)
		int i, n = nums.size();
		for (i = 0; i < k; i++)
		{
			while (!dll.empty() && nums[dll.back()] <= nums[i])
				dll.pop_back();
			dll.push_back(i);
		}
		ans.push_back(nums[dll.front()]);
		for (; i < n; i++)
		{
			while (!dll.empty() && nums[dll.back()] <= nums[i])
				dll.pop_back();
			dll.push_back(i);
			while (dll.front() <= i - k)
				dll.pop_front();
			ans.push_back(nums[dll.front()]);
		}
		return ans;
	}
};