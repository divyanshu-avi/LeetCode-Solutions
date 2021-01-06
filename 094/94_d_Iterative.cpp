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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *trav=root;
        while(!s.empty() || trav)
        {
            if(trav)
            {
                s.push(trav);
                trav = trav->left;
                //Try to visit left subtree first
            }
            else
            {
                trav = s.top();
                s.pop();
                ans.push_back(trav->val);
                trav = trav->right;
                //If an element is popped that means we have already completed its left subtree so now we push it into ans and move to its right subtree.
            }
        }
        return ans;
    }
};