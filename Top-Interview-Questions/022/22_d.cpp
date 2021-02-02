class Solution {
public:
    void recursion(int n, int open, string temp, vector<string> &ans)
    {
        if(!n && !open)
        {
            ans.push_back(temp);
            return;
        }
        if(n>0)
            recursion(n-1, open+1, temp+'(', ans);
        if(open>0)
            recursion(n, open-1, temp+')', ans);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(!n)
            return ans;
        recursion(n, 0, "", ans);
        return ans;
    }
};