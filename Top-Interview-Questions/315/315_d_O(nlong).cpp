class Solution {
public:
	void print(vector<vector<int>>& arr)
	{
		int n = arr.size(), i;
		for (i = 0; i < n; i++)
			cout << arr[i][0] << ' ' << arr[i][1] << '\n';
	}

	void mergesort(vector<vector<int>>& arr, int l, int r, vector<int>& ans)
	{
		if (r - l + 1 <= 1)
			return;
		int mid = l + (r - l) / 2, i, j;
		//cout<<l<<' '<<mid<<' '<<r<<' '<<'\n';
		mergesort(arr, l, mid, ans);
		mergesort(arr, mid + 1, r, ans);
		for (i = l, j = mid + 1; i <= mid; i++)
		{
			while (j <= r && arr[j][0] < arr[i][0])
				j++;
			ans[arr[i][1]] += j - mid - 1;
		}
		vector<vector<int>>::iterator lstart, rstart, end;
		lstart = arr.begin() + l;
		rstart = arr.begin() + mid + 1;
		end = arr.begin() + r + 1;
		inplace_merge(lstart, rstart, end);
		//sort(lstart, end);
	}

	vector<int> countSmaller(vector<int>& nums) {
		int n = nums.size(), i;
		vector<int> ans(n, 0);
		vector<vector<int>> arr;
		for (i = 0; i < n; i++)
			arr.push_back({nums[i], i});//We'll need the original index after sorting to update ans
		//cout<<"Before\n";
		//print(arr);
		mergesort(arr, 0, n - 1, ans);
		//cout<<"\nAfter\n";
		//print(arr);
		return ans;
	}
};