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
    TreeNode* recur(vector<int>& nums, int left, int right)
    {
        if(left>right)
            return NULL;
        if(left == right)
            return new TreeNode(nums[left]);
        int mid = left + (right-left+1)/2;
        return new TreeNode(nums[mid], recur(nums, left, mid-1), recur(nums, mid+1, right));
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recur(nums, 0, nums.size()-1);
    }
};