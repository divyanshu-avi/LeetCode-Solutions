class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int i, j, n = A.size(), ans = 0;
		unordered_map<int, int> hmap;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				++hmap[-A[i] - B[j]];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				ans += hmap[C[i] + D[j]];
		return ans;
	}
};