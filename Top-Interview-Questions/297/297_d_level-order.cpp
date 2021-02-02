/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string ans = "";
		if (!root)
			return ans;
		queue<TreeNode*> Q;
		TreeNode *temp;
		Q.push(root);
		while (!Q.empty())
		{
			temp = Q.front();
			Q.pop();
			if (!temp)
				ans += ". ";
			else
			{
				ans += to_string(temp->val) + " ";
				Q.push(temp->left);
				Q.push(temp->right);
			}
		}
		//cout<<ans;
		ans.pop_back();
		return ans;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data == "")
			return NULL;
		TreeNode *ans = nullptr, *trav;
		stringstream line(data);
		string temp;
		vector<string> tok;
		int num, i = 1;
		queue<TreeNode*> Q;
		while (getline(line, temp, ' ')) //tokenizing the string
		{
			tok.push_back(temp);
		}
		num = stoi(tok[0]);
		ans = new TreeNode(num);
		Q.push(ans);
		while (!Q.empty() && i < tok.size())
		{
			trav = Q.front();
			Q.pop();
			if (tok[i] != ".")
			{
				trav->left = new TreeNode(stoi(tok[i]));
				Q.push(trav->left);
			}
			i++;
			if (tok[i] != ".")
			{
				trav->right = new TreeNode(stoi(tok[i]));
				Q.push(trav->right);
			}
			i++;
		}
		return ans;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));