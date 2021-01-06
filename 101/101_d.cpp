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
    bool recursion(TreeNode* L, TreeNode* R)
    {
        if(!L && !R)
            return true;
        if(!L || !R)
            return false;
        return L->val==R->val && recursion(L->left, R->right) && recursion(L->right, R->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        else
            return recursion(root->left, root->right);
    }
};