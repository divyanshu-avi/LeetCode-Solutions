class Solution {
public:
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int i, int x, int y, vector<string> &ans,int &flag){
        if(i==word.length()){
            ans.push_back(word);
            flag=1;
            return ;
        }
        int m=board.size(), n=board[0].size();
        vector<int> dx={0,0,-1,1}, dy={-1,1,0,0}; //up down right left
        for(int d=0;d<4;d++){
            if(x+dx[d]>=0 && x+dx[d]<m && y+dy[d]>=0 && y+dy[d]<n && board[x+dx[d]][y+dy[d]]==word[i] && visited[x+dx[d]][y+dy[d]]==0){
                visited[x+dx[d]][y+dy[d]]=1;
                dfs(board, visited, word, i+1, x+dx[d], y+dy[d], ans, flag);
                if(flag==1) return ;
            }
        }
        cout<<x<<y<<word[i];
        return ;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        int m=board.size(), n=board[0].size();
        for(int i=0;i<words.size();i++){
            int flag=0;
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(board[j][k]==words[i][0]){
                        vector<vector<int>> visited(m,vector<int>(n,0));
                        visited[j][k]=1;
                        dfs(board, visited, words[i], 1, j, k, ans, flag);
                    }
                    if(flag==1) break;
                }
                if(flag==1) break;
            }
        }
        return ans;
    }
};
