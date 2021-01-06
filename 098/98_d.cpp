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
    bool recursion(TreeNode* root,long long int low, long long int high)
    {
        if(!root)
            return true;
        if(root->val <=low || root->val >=high)
            return false;
        else return recursion(root->left, low, root->val) && recursion(root->right, root->val, high);
    }
    
    bool isValidBST(TreeNode* root) {
        long long int low = -1, high = 1;;
        return recursion(root, low + INT_MIN, high + INT_MAX);
    }
};