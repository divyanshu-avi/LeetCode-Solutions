class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, l, r, u, d, n, temp;
        n = matrix.size();
        for(i=0;i<n/2;i++)
        {
            l = u = i;
            r = d = n-1-i;
            for(j=0;j<r-l;j++)
            {
                temp = matrix[u][l+j];//Store the top left entry
                matrix[u][l+j] = matrix[d-j][l];//Then do shifting in an anti-clockwise fashion
                matrix[d-j][l] = matrix[d][r-j];
                matrix[d][r-j] = matrix[u+j][r];
                matrix[u+j][r] = temp;
            }
        }
    }
};