class Solution {
public:
	int m, n, count;
	vector<vector<bool>> visited;
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	unordered_set<string> hset;

	class Trie {
	public:
		/** Initialize your data structure here. */
		vector<Trie*> child;
		bool end;

		Trie() {
			child.resize(26, NULL);
			end = false;
		}

		/** Inserts a word into the trie. */
		void insert(string word) {
			int i, n = word.length();
			Trie *cur = this;
			for (i = 0; i < n; i++)
			{
				if (!cur->child[word[i] - 'a'])
					cur->child[word[i] - 'a'] = new Trie;
				cur = cur->child[word[i] - 'a'];
			}
			cur->end = true;

		}
	};


	void dfs(vector<vector<char>>& board, int x, int y, string& temp, Trie *root)
	{
		temp.push_back(board[x][y]);
		visited[x][y] = true;
		if (root->end && hset.find(temp) == hset.end())
		{
			hset.insert(temp);
			count--;
		}

		int k, i, j;
		for (k = 0; k < 4 && count; k++)
		{
			i = x + dx[k];
			j = y + dy[k];
			if (i >= 0 && j >= 0 && i < m && j < n && !visited[i][j] && root->child[board[i][j] - 'a'])
				dfs(board, i, j, temp, root->child[board[i][j] - 'a']);
		}
		visited[x][y] = false;
		temp.pop_back();
	}


	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		m = board.size(), n = board[0].size();
		visited.resize(m, vector<bool>(n, 0));
		string temp = "";
		int i, j, k = words.size();
		count = k;
		Trie *root = new Trie();
		for (i = 0; i < k; i++)
			root->insert(words[i]);

		for (i = 0; i < m && count; i++)
			for (j = 0; j < n && count; j++)
				if (root->child[board[i][j] - 'a'])
					dfs(board, i, j, temp, root->child[board[i][j] - 'a']);
		vector<string> ans;
		for (auto it = hset.begin(); it != hset.end(); it++)
			ans.push_back(*it);
		return ans;
	}
};