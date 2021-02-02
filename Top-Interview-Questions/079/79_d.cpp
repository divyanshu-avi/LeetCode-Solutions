class Solution {
public:
    vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
    bool dfs(int x, int y, int pos, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited)
    {
        visited[x][y] = true;
        bool ok = false;
        if(pos == word.length())
        {
            ok = true;
        }
        for(int i=0;i<4 && !ok;i++)
        {
            int m = x + dx[i], n = y + dy[i];
            if(m>=0 && n>=0 && m<board.size() && n<board[0].size() && !visited[m][n] && board[m][n] == word[pos])
                ok = dfs(m, n, pos+1, board, word, visited);
        }
        visited[x][y] = false;
        return ok;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), i ,j;
        bool ok = false;
        vector<vector<bool>> visited(m, vector<bool>(n, 0));
        
        for(i=0;i<m && !ok;i++)
            for(j=0;j<n && !ok;j++)
                if(board[i][j] == word[0])
                    ok = dfs(i, j, 1, board, word, visited);
        return ok;
    }
};