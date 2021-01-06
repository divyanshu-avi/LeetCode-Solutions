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
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        return solve(root,{INT_MIN,INT_MAX});
    }
    
    bool solve(TreeNode* root, pair<int,int> limit){
        
        if(root==NULL)
            return true;
        
        if(root->val < limit.first || root->val > limit.second)
            return false;

         if(root->left){
            
            if(root->val <= root->left->val){
               
                cout<<"point 2";
                 return false;
            }
            if(!solve(root->left,{limit.first, root->val-1} )){
                
                cout<<"eccecuted";
                return false;
            }
            
        }
        
        if(root->right){
            
            if(root->val >= root->right->val){
                cout<<"3";
                return false;}
                
            if(!solve(root->right,{root->val+1,limit.second})){
                cout<<"4";
                return false;}
            
        }
        
        return true;
        
    }
};