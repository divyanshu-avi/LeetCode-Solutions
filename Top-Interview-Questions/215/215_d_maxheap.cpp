class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> pq;
		int i, n = nums.size();

		for (i = 0; i < n; i++)
			pq.push(nums[i]);

		for (i = 1; i < k; i++)
			pq.pop();
		return pq.top();
	}
};