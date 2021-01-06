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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);
        while(!q.empty()){
            TreeNode* r=q.front();
            q.pop();
            TreeNode* l=q.front();
            q.pop();
            if(l==NULL && r==NULL)
                continue;
            if((r==NULL&&l!=NULL) || (r!=NULL&&l==NULL))
                return 0;
            else if(r->val!=l->val)
                return 0;
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return 1;
    }
};
