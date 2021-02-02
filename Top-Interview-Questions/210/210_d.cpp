class Solution {
public:
	vector<int> findOrder(int n, vector<vector<int>>& edge) {
		int i, count = n, temp;
		vector<int> indeg(n, 0);
		vector<vector<int>> adj(n, vector<int>());
		vector<int> ans;

		for (i = 0; i < edge.size(); i++)
		{
			adj[edge[i][1]].push_back(edge[i][0]);
			indeg[edge[i][0]]++;
		}
		queue<int> Q;
		for (i = 0; i < n; i++)
			if (indeg[i] == 0)
				Q.push(i);

		while (!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			count--;
			ans.push_back(temp);
			for (i = 0; i < adj[temp].size(); i++)
				if (--indeg[adj[temp][i]] == 0)
					Q.push(adj[temp][i]);
		}

		return count == 0 ? ans : vector<int>();
	}
};