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
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        
        int n = nums.size();
        if(n==0)
            return NULL;
        
        return solve(0,n-1,nums);
        
    }
    
    TreeNode* solve(int l,int r, vector<int>&nums){
        
        if(l>r)
            return NULL;
        
        int mid = l + (r-l)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = solve(l,mid-1,nums);
        root->right = solve(mid+1,r,nums);
        
        return root;
        
    }
};