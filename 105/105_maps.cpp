class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        unordered_map<int,int> mp;
        
        for(int i =0; i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        return solve(0,0,inorder.size()-1,preorder,inorder,mp);
        
    }
    
    TreeNode* solve(int index, int instart, int inend, vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp){
        
        if(index>preorder.size()-1 || instart>inend)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int rootindex=mp[preorder[index]];
        
        
        root->left = solve(index+1,instart,rootindex-1,preorder,inorder,mp);
        root->right = solve(index+1+rootindex-instart,rootindex+1,inend,preorder,inorder,mp);
        
        return root;
        
    }
};