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
    TreeNode* recur(vector<int>& pre, vector<int>& in, int preL, int preR, int inL, int inR, unordered_map<int, int>& idx)
    {
        if(inL>inR)
            return NULL;
        
        //int pos = find(in.begin()+inL, in.begin()+inR+1, pre[preL]) - in.begin();
        int pos = idx[pre[preL]];
        TreeNode *root = new TreeNode(pre[preL]);//pre[preL] has the value of root
        int sizeL = pos-inL;//size of inorder array for left subtree.
        root->left = recur(pre, in, preL+1, preL+sizeL, inL, pos-1, idx);
        root->right = recur(pre, in, preL+sizeL+1, preR, pos+1, inR, idx);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(!n)
            return NULL;
        unordered_map<int, int> idx;
        for(int i=0;i<n;i++)
            idx.insert({inorder[i], i});
        return recur(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, idx);
    }
};