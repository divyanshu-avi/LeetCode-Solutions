class Solution {
public:
    int maxDepth(TreeNode* root) {
        
    
        int maxlen = 0;
        stack<pair<TreeNode*,int>> st;
        TreeNode* curr=root;
        int len =0;
        
        while(!st.empty() || curr){
            
            if(curr){
                st.push({curr,len});
                curr = curr->left;
                len +=1;
            }else{
                maxlen = max(maxlen,len);
               curr = st.top().first;
                len = st.top().second;
                st.pop();
                curr= curr->right;
                len+=1;
                
            }
          
        }
        
        return maxlen;
    }
};