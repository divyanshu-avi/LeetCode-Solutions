/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	bool inorder(TreeNode* root, int& k, int &ans)
	{
		if (!root)
			return false;
		if (inorder(root->left, k, ans)) return true;
		if (k == 1)
		{
			ans = root->val;
			return true;
		}
		k--;
		return inorder(root->right, k , ans);
	}

	int kthSmallest(TreeNode* root, int k) {
		int ans;
		inorder(root, k, ans);
		return ans;
	}
};