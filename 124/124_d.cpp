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
    int maxsum(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        int left = maxsum(root->left, ans);
        int right = maxsum(root->right, ans);
        int num = max({left, right, 0});
        ans = max({ans, num+root->val, left + right + root->val});
        return num + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxsum(root, ans);
        return ans;
    }
};