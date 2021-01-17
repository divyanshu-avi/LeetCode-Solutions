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
	int kthSmallest(TreeNode* root, int k) {
		TreeNode *trav = root;
		stack<TreeNode*> st;
		while (trav || !st.empty())
		{
			if (trav)
			{
				st.push(trav);
				trav = trav->left;
			}
			else
			{
				trav = st.top();
				st.pop();
				if (--k == 0) return trav->val;
				trav = trav->right;
			}
		}
		return -1;
	}
};