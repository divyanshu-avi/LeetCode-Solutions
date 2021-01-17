/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool findpath(TreeNode *root, TreeNode *target, vector<TreeNode*> &ans)
	{
		if (!root)
			return false;
		ans.push_back(root);
		if (root == target)
			return true;
		bool ok = findpath(root->left, target, ans) || findpath(root->right, target, ans);
		if (!ok)
			ans.pop_back();
		return ok;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> pathp, pathq;
		findpath(root, p, pathp);
		findpath(root, q, pathq);

		int i, n = min(pathp.size(), pathq.size());
		for (i = 0; i < n && pathp[i] == pathq[i]; i++);
		return pathp[i - 1];
	}
};