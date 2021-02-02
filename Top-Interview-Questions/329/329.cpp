class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> a(n,vector<int>(m,0));
        int ans =1;
        for(int i =0; i<n; i++)
            for(int j =0; j<m; j++){
                if(!a[i][j])
                   solve(matrix,a,i,j);
                ans = max(a[i][j],ans);
            }
        return ans;
        
    }
    
    int solve(vector<vector<int>>& matrix, vector<vector<int>>& a, int i,int j){
        
        if(a[i][j] != 0)
            return a[i][j];
        
        int ans = 1;
        
        if(j-1>=0 && matrix[i][j]<matrix[i][j-1]) 
            ans = max(ans, 1+ solve(matrix,a,i,j-1));

        if(j+1<matrix[0].size() && matrix[i][j]<matrix[i][j+1])
            ans = max(ans,1+solve(matrix,a,i,j+1));
  
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j])
            ans = max(ans,1+solve(matrix,a,i-1,j));
            
        if(i+1<matrix.size() && matrix[i][j]<matrix[i+1][j])        
            ans = max(ans,1+solve(matrix,a,i+1,j));
    
        
        return a[i][j] = ans;
    }   
      
    
};