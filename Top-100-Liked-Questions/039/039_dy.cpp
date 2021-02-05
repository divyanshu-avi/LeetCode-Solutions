class Solution {
public:
	void solve(vector<int>& a, int pos, int sum, vector<int>& temp, vector<vector<int>>& ans)
	{
		if (sum < 0) {
			return;
		}
		if (sum == 0)
		{
			ans.push_back(temp);
			return;
		}
		int n = a.size(), i;
		if (pos == n) //reachced end
			return;
		for (i = pos; i < n ; ++i)
		{
			temp.push_back(a[i]);
			solve(a, i, sum - a[i], temp, ans);
			temp.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& a, int target) {
		sort(a.begin(), a.end());
		vector<vector<int>> ans;
		vector<int> b;
		solve(a, 0, target, b, ans);
		return ans;
	}
};