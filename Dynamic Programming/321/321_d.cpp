class Solution {
public:
	void print(vector<int>& arr)
	{
		int i, n = arr.size();
		for (i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}

	vector<int> maxNumber(vector<int>& a1, vector<int>& a2, int k) {
		int n1 = a1.size(), n2 = a2.size(), i;
		vector<int> v1, v2, ans;
		for (i = 0; i <= k; i++)
		{
			if (i > n1)
				break;
			if (k - i > n2)
				continue;
			v1 = getNum(a1, i);
			v2 = getNum(a2, k - i);
			v1 = merge(v1, v2);//merge to create largest num (not a normal merge)
			if (ans.empty() || bigger(v1, ans))
			{
				ans = v1;
				//print(v1);
				//print(v2);
				//cout<<'\n';
			}
		}
		return ans;
	}
	bool bigger(vector<int>& v1, vector<int>&v2, int idx1 = 0, int idx2 = 0)//check if v1's number is bigger
	{
		int n1 = v1.size() - idx1, n2 = v2.size() - idx2, i = 0, j = 0;
		if (n1 <= 0)
			return false;
		if (n2 <= 0)
			return true;
		int x, y;
		while (i < n1 || j < n2)
		{
			x = i == n1 ? -1 : v1[idx1 + i++];
			y = j == n2 ? -1 : v2[idx2 + j++];
			if (x != y)
				return x > y;
		}
		return false;//If both arrays are same why waste time
	}

	vector<int> merge(vector<int>& v1, vector<int>& v2)
	{
		int n1 = v1.size(), n2 = v2.size(), i = 0, j = 0, x, y;
		vector<int> ans;
		while (i < n1 || j < n2)
		{
			if (bigger(v1, v2, i, j))
				ans.push_back(v1[i++]);
			else
				ans.push_back(v2[j++]);
		}
		return ans;
	}

	vector<int> getNum(vector<int>& arr, int k)//The most important function of this question
	{
		int i, j = 0, n = arr.size();
		vector<int> ans(k);
		for (i = 0; i < n; i++)
		{
			while (j > 0 && arr[i] > ans[j - 1] && n - i >= k - j + 1)
				j--;
			if (j < k)
				ans[j++] = arr[i];
		}
		return ans;
	}
};