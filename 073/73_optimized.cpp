class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int c=0;
        int row=mat.size(),col=mat[0].size();
        for(int i=0;i<row;i++)
        {
            if(mat[i][0]==0)
                c=1;
            for(int j=1;j<col;j++)
            {
                if(mat[i][j]==0)
                    mat[0][j]=mat[i][0]=0;
            }
        }
        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=1;j--)
            {
                if(mat[i][0]==0 || mat[0][j]==0)
                    mat[i][j]=0;
            }
            if(c==1)
                mat[i][0]=0;
        }
    }
};