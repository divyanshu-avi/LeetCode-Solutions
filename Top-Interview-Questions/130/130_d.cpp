class Solution {
public:
    vector<int> dx = {0,1,0,-1}, dy = {1,0,-1,0};
    
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited)
    {
        int i, j, k, m = board.size(), n = board[0].size();
        
        visited[x][y] = true;
        for(k=0;k<4;k++)
        {
            i = x + dx[k];
            j = y + dy[k];
            if(i>=0 && j>=0 && i<m && j<n && board[i][j]=='O' && !visited[i][j])
                dfs(i, j, board, visited);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m , n, i, j;
        m = board.size();
        if(!m)
            return;
        n = board[0].size();
        if(!n)
            return;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(i=0;i<n;i++)
        {
            if(board[0][i] == 'O' && !visited[0][i])
                dfs(0, i, board, visited);
            if(board[m-1][i] == 'O' && !visited[m-1][i])
                dfs(m-1, i, board, visited);
        }
        for(i=1;i<m-1;i++)
        {
            if(board[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, board, visited);
            if(board[i][n-1] == 'O' && !visited[i][n-1])
                dfs(i, n-1, board, visited);
        }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
        
    }
};