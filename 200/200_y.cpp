class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count  = 0;
        
        for(int i = 0; i<grid.size(); i++){
            for(int j =0; j< grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    solve(grid,i,j);
                    count++;}
                
            }
        }
        
        
        return count;
    }
    
    void solve(vector<vector<char>>& grid, int i, int j){
        
        
        if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size())
            return;
        
        if(grid[i][j]=='1'){
            
            grid[i][j] = '0';
            
            solve(grid,i+1,j);
            solve(grid,i-1,j);
            solve(grid,i,j+1);
            solve(grid,i,j-1);
        }
        
        
        return;
    }
};