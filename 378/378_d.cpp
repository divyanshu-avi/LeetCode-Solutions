class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int i, m = matrix.size(), n = matrix[0].size(), temp;
		pair<int, int> ans;
		vector<int> idx(n, 1);
		priority_queue<pair<int, int>> pq;
		for (i = 0; i < n; i++)
			pq.push({ -matrix[0][i], i});
		while (k--)
		{
			ans = pq.top();
			pq.pop();
			temp = idx[ans.second];
			if (temp < m)
			{
				pq.push({ -matrix[temp][ans.second], ans.second});
				idx[ans.second]++;
			}
		}
		return -ans.first;
	}
};