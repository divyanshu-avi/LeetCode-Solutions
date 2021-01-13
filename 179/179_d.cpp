class Solution {
public:
	static bool customsort(string x, string y)
	{
		return (x + y) > (y + x);
	}

	string largestNumber(vector<int>& nums) {
		vector<string> temp;
		int i, n = nums.size();
		bool zero = 1;
		for (i = 0; i < n; i++)
		{
			temp.push_back(to_string(nums[i]));
			if (nums[i])
				zero = 0;
		}
		if (zero)
			return "0";
		sort(temp.begin(), temp.end(), customsort);
		string ans = "";
		for (i = 0; i < n; i++)
			ans += temp[i];
		return ans;
	}
};