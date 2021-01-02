class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> ans;
        
        int left = 0,right = m-1,top = 0, bottom = n-1;
        int direction=0;
        
        while(left<=right && top<=bottom){
           
            if(direction == 0){
                
                for(int i =left ; i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                
                top++;
                
            }
            else if(direction == 1){
                
                for(int i =top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                
            }else if(direction == 2){
                
                for(int i = right; i>=left; i--)
                    ans.push_back(matrix[bottom][i]);
                    bottom--;   
                
            }else if (direction == 3){
                for(int i = bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left = left+1;
            }
            direction = (direction+1)%4;
            
            
        }
        
        
        return ans;
        
    }
};
