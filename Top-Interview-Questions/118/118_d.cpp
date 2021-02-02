class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        if(n==0)
            return ans;
        ans.push_back({1});
        if(n==1)
            return ans;
        int i, j;
        for(i=1;i<n;i++)
        {
            ans.push_back(vector<int>());
            ans[i].push_back(1);
            for(j=1;j<i;j++)
                ans[i].push_back(ans[i-1][j] + ans[i-1][j-1]);
            ans[i].push_back(1);
        }
        return ans;
    }
};