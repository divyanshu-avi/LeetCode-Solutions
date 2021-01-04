class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, m, n;
        m = matrix.size();
        if(!m) return;
        n = matrix[0].size();
        bool col = 0;
        //For O(1) space we will store the required info in the given matrix.
        //Fist row and column will be utilized for this.
        //If matrix[0][0] = 0 we are not sure if we have zero out the col/row/both.
        //For this we use col (boolean variable).
        for(i=0;i<m;i++)
        {
            if(matrix[i][0] == 0)
                col = 1;//This means first col has to be filled with zeroes.
            for(j=1;j<n;j++)//j=0 case already handled
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        }
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                cout<<matrix[i][j]<<' ';
            cout<<'\n';
        }*/
        //We have to handle 1st row after the rest of the matrix because it contains info.
        for(i=1; i<m; i++)
        {
            for(j=1;j<n;j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
        }        
        if(matrix[0][0] == 0)
            for(j=1;j<n;j++)
                matrix[0][j] = 0;
        if(col)
            for(i=0;i<m;i++)
                matrix[i][0] = 0;
    }
};