class Solution {
public:
	vector<vector<int>> adj;
	vector<bool> visited;
	vector<bool> marked;

	bool visit(int n)
	{
		if (visited[n])//If already visited means a cycle
			return true;
		if (marked[n])//If this is marked means it was checked before and no cycle was detected
			return false;
		visited[n] = true;
		int i;
		bool cycle = false;
		for (i = 0; i < adj[n].size() && !cycle; i++)
			cycle = visit(adj[n][i]);
		visited[n] = false;
		return cycle;
	}

	void mark(int n)
	{
		marked[n] = true;
		for (int i = 0; i < adj[n].size(); i++)
			if (!marked[adj[n][i]])
				mark(adj[n][i]);
	}

	bool canFinish(int n, vector<vector<int>>& edge) {
		adj.resize(n, vector<int>());
		visited.resize(n, 0);
		marked.resize(n, 0);

		int i;
		bool cycle = false;

		for (i = 0; i < edge.size(); i++)
		{
			adj[edge[i][1]].push_back(edge[i][0]);
		}

		for (i = 0; i < n && !cycle; i++)
		{
			if (!marked[i])
			{
				cycle = visit(i);
				mark(i);
			}
		}
		return !cycle;
	}
};