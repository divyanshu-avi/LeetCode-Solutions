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
        stack<TreeNode*> s;
        TreeNode* temp=root;
        int last=INT_MIN, flag=0;
        while(!s.empty() || temp){
            if(temp){
                s.push(temp);
                temp=temp->left;
            }
            else{
                temp=s.top();
                if(last==INT_MIN){
                    if(flag==0 && temp->val==INT_MIN){
                        flag=1;
                    }
                    else if(flag==1 && temp->val==INT_MIN){
                        return 0;
                    }
                }
                else if(temp->val<=last)
                    return 0;
                last=temp->val;
                s.pop();
                temp=temp->right;
            }
        }
        return 1;
    }
};
