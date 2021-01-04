class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, m, n;
        m = matrix.size();
        if(!m) return;
        n = matrix[0].size();
        bool col = 0, row = 0;
        //For O(1) space we will store the required info in the given matrix.
        //Fist row and column will be utilized for this.
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(matrix[i][j] == 0)
                {
                    //Seperately handling the case when 0 present in first row or col
                    if(i==0)
                        row=1;
                    if(j==0)//Dont use else if here as both can be true
                        col=1;
                    else
                        matrix[i][0] = matrix[0][j] = 0;
                }
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<matrix[i][j]<<' ';
            cout<<'\n';
        }*/
        
        for(j=1;j<n;j++)
            if(matrix[0][j] == 0)
                for(i=1;i<m;i++)
                    matrix[i][j] = 0;
        for(i=1;i<m;i++)
            if(matrix[i][0] == 0)
                for(j=1;j<n;j++)
                    matrix[i][j] = 0;
        if(row)
            for(j=0;j<n;j++)
                matrix[0][j] = 0;
        if(col)
            for(i=0;i<m;i++)
                matrix[i][0] = 0;
    }
};