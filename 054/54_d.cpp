class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int l, r, u, d, i, j, m = matrix.size(), n;
        vector<int> ans;
        if(!m) return ans;
        n = matrix[0].size();
        if(!n) return ans;
        l = u = 0;
        r = n-1;
        d = m-1;
        while(l<r && u<d)
        {
            i = u; j = l-1;
            while(++j <= r)
                ans.push_back(matrix[i][j]);//Left to Right
            j--;
            while(++i <= d)
                ans.push_back(matrix[i][j]);//Up to Down
            i--;
            while(--j >= l)
                ans.push_back(matrix[i][j]);//Right to left
            j++;
            while(--i > u)
                ans.push_back(matrix[i][j]);//Down to Up
            cout<<l<<r<<u<<d<<' ';
            u++; d--; l++; r--;//Updating boundaries
        }
        //If l==r or u==d then all four motions are not defined so handle that seperately.
        if(u==d)
            while(l <= r)
                ans.push_back(matrix[u][l++]);//Extra style points 🤩
        if(l==r)
            while(u <= d)
                ans.push_back(matrix[u++][l]);
        return ans;
    }
};