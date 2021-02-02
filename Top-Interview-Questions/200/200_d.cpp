class Solution {
public:
	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	vector<vector<bool>> visited;

	void visit(vector<vector<char>>& grid, int x, int y)
	{
		int m = grid.size(), n = grid[0].size(), i, j, k;
		visited[x][y] = 1;

		for (k = 0; k < 4; k++)
		{
			i = x + dx[k];
			j = y + dy[k];
			if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == '1' && !visited[i][j])
				visit(grid, i, j);
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size(), n = grid[0].size(), i, j, ans = 0;
		visited.resize(m, vector<bool>(n, 0));
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
				if (grid[i][j] == '1' && !visited[i][j])
				{
					ans++;
					visit(grid, i, j);
				}
		return ans;
	}
};