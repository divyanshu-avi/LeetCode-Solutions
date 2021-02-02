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
        
        solve(ans,root,0);
        
        for(int i =0; i<ans.size(); i++){
            if(i%2)
                reverse(ans[i].begin(),ans[i].end());
        }
        
        
        return ans;
        
        
    }
    
    void solve(vector<vector<int>> &ans,TreeNode* root, int level){
        
        if(root ==NULL)
            return;
        
        if(level == ans.size())
            ans.push_back({root->val});
        else{
                ans[level].push_back(root->val);    
        }
        
        solve(ans,root->left,level+1);
        solve(ans,root->right,level+1);
        return;
        
        
    }
};