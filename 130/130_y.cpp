class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int n = board.size();
        if(n==0)
            return;
        
        int m  = board[0].size();
        
        if(m==0 )
            return;
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
               
                if((i==0 || i == n-1 || j == 0 || j==m-1) && board[i][j]=='O')
                    swit(i,j,board);
                
            }
        }
        
        for(int i =0; i<n; i++){
            for(int j =0; j<m ; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        
        for(int i =0 ; i<n; i++){
            for(int j =0; j<m ; j++){
                
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='a')
                    board[i][j]='O';
                
            }
        }
        
        return;
    }
    
    void swit(int i, int j, vector<vector<char>>& board){
            
            if(i==board.size() || i<0)
                return;
            if(j == board[0].size() || j<0)
                return;
            
            if(board[i][j]=='O'){
                
                board[i][j]='a';
                swit(i,j+1,board);
                swit(i-1,j,board);
                swit(i+1,j,board);
                swit(i,j-1,board);
                
            }
            
            return;
    }
};