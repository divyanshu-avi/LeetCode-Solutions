class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
     
        int n = matrix.size();
        int m = matrix[0].size();
        
        set<int> rows;
        set<int> cols;
        
        for(int i=0; i< n;i++){
            for(int j=0; j<m;j++){
                if(matrix[i][j]==0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        vector<int> zeros(m,0);
     
        for(auto rc: rows){
                matrix[rc]= zeros;
        }
        
        for(auto col: cols){
            for(int i =0; i<n;i++){
                matrix[i][col]=0;
            }
        }
        
        return;
                
    }
};