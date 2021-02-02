class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ok = 1;
        int i, j, k, l;
        unordered_set<char> hochuka;
        for(i=0;i<9 && ok;i++)//ROWS
        {
            hochuka.clear();
            for(j=0;j<9 && ok;j++)
            {
                if(board[i][j] != '.' && hochuka.find(board[i][j])!=hochuka.end())
                {
                    ok=0;
                    cout<<1;
                }
                else
                    hochuka.insert(board[i][j]);
            }
        }
        for(j=0;j<9 && ok;j++)//COLS
        {
            hochuka.clear();
            for(i=0;i<9 && ok;i++)
            {
                if(board[i][j] != '.' && hochuka.find(board[i][j])!=hochuka.end())
                {
                    ok=0;
                    cout<<2;
                }
                else
                    hochuka.insert(board[i][j]);
            }
        }
        for(i=0;i<9 && ok;i+=3)//3x3
        {
            for(j=0;j<9 && ok;j+=3)
            {
                hochuka.clear();
                for(k=0;k<3 && ok;k++)
                    for(l=0;l<3 && ok;l++)
                    {
                        if(board[i+k][j+l] != '.' && hochuka.find(board[i+k][j+l])!=hochuka.end())
                        {
                            ok=0;
                            cout<<3;
                        }
                        else
                            hochuka.insert(board[i+k][j+l]);
                    }
            }
        }
        return ok;
    }
};