class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int i, j, live, k, x, y;
		int n = board.size(), m = board[0].size();
		/*1 = live
		  0 = dead
		 -1 = live->dead
		  2 = dead->live*/
		vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1}, dy = {1, 1, 0, -1, -1, -1, 0, 1};
		for (x = 0; x < n; x++)
			for (y = 0; y < m; y++)
			{
				live = 0;
				for (k = 0; k < 8; k++)
				{
					i = x + dx[k];
					j = y + dy[k];
					if (i < n && j < m && i >= 0 && j >= 0 && abs(board[i][j]) == 1)
						live++;
				}
				if (board[x][y] == 1 && (live < 2 || live > 3))
					board[x][y] = -1;
				else if (board[x][y] == 0 && live == 3)
					board[x][y] = 2;
			}

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				if (board[i][j] == 2)
					board[i][j] = 1;
				else if (board[i][j] == -1)
					board[i][j] = 0;
			}
	}
};