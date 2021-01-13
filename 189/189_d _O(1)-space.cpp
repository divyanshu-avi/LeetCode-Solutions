class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int n = nums.size(), i, temp, pred, req = n;
		k = k % n;
		if (!k)
			return;
		for (i = 0; i < k && req; i++)
		{
			req--;
			temp = nums[i];
			pred = i - k;
			if (pred < 0)
				pred = n + pred;
			while (pred != i)
			{
				req--;
				nums[(pred + k) % n] = nums[pred];
				pred -= k;
				if (pred < 0)
					pred = n + pred;
			}
			nums[(pred + k) % n] = temp;
		}
	}
};