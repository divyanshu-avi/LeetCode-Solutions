class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == ".*")//.* can match with anything
            return true;
        int m = s.length(), n = p.length(), i, j;
        bool match[m+1][n+1];
        match[0][0] = true;
        for(i=1;i<=m;i++)
            match[i][0] = false;
        for(i=0;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==0)
                {
                    if(p[j-1] == '*')//j>=2 is guaranteed because something has to come b4 the *
                        match[i][j] = match[i][j-2];
                    else
                        match[i][j] = false;
                }
                else if(s[i-1] == p[j-1] || p[j-1] == '.')
                    match[i][j] = match[i-1][j-1];
                else if(p[j-1] == '*')//j>=2 is guaranteed because something has to come b4 the *
                {
                    if( p[j-2]=='.' || p[j-2]==s[i-1] )
                        match[i][j] = match[i-1][j] || match[i][j-2];
                    else
                        match[i][j] = match[i][j-2];
                }
                else
                    match[i][j] = false;
            }
        }
        for(i=0;i<=m;i++)
        {
            for(j=0;j<=n;j++)
                cout<<match[i][j]<<' ';
            cout<<'\n';
        }
        return match[m][n];
    }
};