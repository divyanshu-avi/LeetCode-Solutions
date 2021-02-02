class Solution {
public:
	vector<int> nums, random;
	int n;
	Solution(vector<int>& nums) {
		this->nums = nums;
		this->random = nums;
		n = nums.size();
		srand(time(0));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return nums;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		int i;
		for (i = 0; i < n; i++)
			swap(random[i], random[rand() % (n - i) + i]);
		return random;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */