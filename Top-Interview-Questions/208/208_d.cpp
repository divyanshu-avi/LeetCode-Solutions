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

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie* cur = this;
		int i, n = word.length();
		for (i = 0; i < n && cur ; i++)
			cur = cur->child[word[i] - 'a'];
		return (cur != NULL && cur->end);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie* cur = this;
		int i, n = prefix.length();
		for (i = 0; i < n && cur ; i++)
			cur = cur->child[prefix[i] - 'a'];
		return (cur != NULL);
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */