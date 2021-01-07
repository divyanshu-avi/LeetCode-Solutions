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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        stack<pair<TreeNode*, int>> st;
        pair<TreeNode*, int> temp = {root, 1};
        while(temp.first || !st.empty())
        {
            if(temp.first)
            {
                st.push(temp);
                temp = {temp.first->left, temp.second+1};
            }
            else
            {
                temp = st.top();
                st.pop();
                ans = max(ans, temp.second);
                temp = {temp.first->right, temp.second+1};
            }
        }
        return ans;
    }
};