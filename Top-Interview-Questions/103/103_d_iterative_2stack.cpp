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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        stack<TreeNode *> zig, zag;//I know the names are confusing but I couldn't stop myself.
        int i;
        bool flip = 1;
        zig.push(root);
        while(!zig.empty() || !zag.empty())
        {
            ans.push_back(vector<int>());
            if(flip)
            {
                while(!zig.empty())
                {
                    root = zig.top();
                    zig.pop();
                    ans.back().push_back(root->val);
                    if(root->left)
                        zag.push(root->left);
                    if(root->right)
                        zag.push(root->right);
                }
                flip = 0;
            }
            else
            {
                while(!zag.empty())
                {
                    root = zag.top();
                    zag.pop();
                    ans.back().push_back(root->val);
                    if(root->right)
                        zig.push(root->right);
                    if(root->left)
                        zig.push(root->left);
                }
                flip = 1;
            }
        }
        return ans;
    }
};