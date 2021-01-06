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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        solve(ans,root,0);
        return ans;
        
    }
    
    void solve(vector<vector<int>> &ans, TreeNode* root,int level){
        
        if(root == NULL)
            return ;
        
        if(level==ans.size()){
            ans.push_back({root->val});
        }else{
            ans[level].push_back(root->val);
        }
        
        solve(ans,root->left,level +1);
        solve(ans,root->right,level +1);
        
        return;
        
    }
};