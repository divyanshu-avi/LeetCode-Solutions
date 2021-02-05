class Solution {
public:
	int jump(vector<int>& nums) {

		int fuel = 0, ans = 0, reach = 0;

		for (int i = 0; i < nums.size() - 1; ++i) {

			reach = max(reach, nums[i]);
			if (fuel == 0) {
				++ans;
				fuel = reach;
			}
			reach--;
			fuel--;

		}

		return ans;
	}

};