class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j =0; j<board[0].size();j++){
                if(board[i][j]==word[0] && check(board,i,j,word,0))
                    return true;
            }
        }
        
     return false;   
        
    }
    
    bool check(vector<vector<char>>& board, int i, int j, string& word, int index){
        
        if(index >=word.size())
            return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
            return false;
        if(board[i][j]!=word[index])
            return false;
        char temp = board[i][j];
        board[i][j]=' ';
        if(check(board,i-1,j,word,index+1) ||check(board,i,j-1,word,index+1) || check(board,i+1,j,word,index+1) ||check(board,i,j+1,word,index+1))
        return true;
        board[i][j]=temp;
        return false; 
    }
    
};