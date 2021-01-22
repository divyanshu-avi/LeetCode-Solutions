class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++)
                update(i,j,board);
        }
        
        for(int i =0; i<n; i++)
            for(int j =0; j<m; j++){
                if(board[i][j]==-1 || board[i][j] == 1)
                    board[i][j] = 1;
                else{
                    board[i][j] = 0;
                }}
                    
        return;
    }
    
    void update(int x, int y, vector<vector<int>> &board){
        
        int count = 0;
        int original = board[x][y];
        int ans=1;
        
        for(int i = -1; i<2; i+=1){
            for(int j = -1; j<2; j+=1){
                
                if(x+i<0 || x+i>=board.size() || y+j>=board[0].size() || y+j<0 || (i==0 && j==0))
                    continue;
                if(board[x+i][y+j]>0)
                count += 1;
                
            }
        }
        
        cout<<count<<" ";
        
        if(original==0){
            if(count==3)
                board[x][y] = -1;
            else board[x][y] = -2;
        }else if(original == 1){
            if(count<2 || count >3)
                board[x][y] = 2;
        }
        cout<< board[x][y]<<endl;
        return;
        
    }
    
    
};