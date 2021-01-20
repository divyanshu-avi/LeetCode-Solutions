class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        if(target<matrix[0][0] || target >matrix[n-1][m-1])
            return false;
        
        int r = n-1;
        int c = 0;
            
        while(r>=0 && c <m){
            if(matrix[r][c]==target)
                return true;
            if(matrix[r][c]>target)
                r--;
            else c++;
            
        }
        return false;
        
    }
};