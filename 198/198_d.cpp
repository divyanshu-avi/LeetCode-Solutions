class Solution {
public:
	int rob(vector<int>& nums) {
		int i, n = nums.size();
		if (!n)
			return 0;
		if (n <= 2)
			return *max_element(nums.begin(), nums.end());
		int n1, n2 = nums[0], ans, temp;
		n1 = ans = max(nums[0], nums[1]);
		for (i = 2; i < n; i++)
		{
			temp = n1;
			n1 = max(n2 + nums[i], n1);//At each house we have 2 options - rob or leave.
			n2 = temp;
			ans = max(ans, n1);
		}
		return ans;
	}
};