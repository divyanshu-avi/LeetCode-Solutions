class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> dp;
    int m, n, ans;
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

    int visit(int x, int y, int len, vector<vector<int>>& matrix)
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        visited[x][y] = true;
        int i, j, k, temp = 0;
        for (k = 0; k < 4; k++)
        {
            i = x + dx[k];
            j = y + dy[k];
            if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j] && matrix[i][j] > matrix[x][y])
                temp = max(temp, visit(i, j, len + 1, matrix));
        }
        ans = max(ans, len + temp);
        dp[x][y] = temp + 1;
        visited[x][y] = false;
        return dp[x][y];

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        ans = 0;
        visited.resize(m, vector<bool>(n, 0));
        dp.resize(m, vector<int>(n, -1));
        int i, j;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (dp[i][j] == -1)
                    visit(i, j, 1, matrix);
        return ans;
    }
};