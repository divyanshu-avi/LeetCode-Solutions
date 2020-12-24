class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, n = strs.size();
        string ans = "";
        if(n == 0)
            return ans;
        ans = strs[0];
        for(i=1;i<n;i++)
        {
            for(j=0;j<ans.length() && ans[j] == strs[i][j];j++);
            ans = ans.substr(0, j);                
        }
        return ans;
    }
};