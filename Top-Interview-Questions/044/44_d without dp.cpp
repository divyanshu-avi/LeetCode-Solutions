class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, star=-1, checkpoint=-1, m = s.length(), n = p.length();
        
        while(i<m)
        {
            if(j<n && (p[j] == s[i] || p[j] == '?'))
            {
                i++; j++;
            }
            else if(j<n && p[j] == '*')//First assume * matches ""
            {
                star = j;
                j++;
                checkpoint = i;
            }
            else if(star != -1)//Last star's assumption was wrong, so make it consume 1 more character
            {
                j = star+1;
                checkpoint++;
                i = checkpoint;
            }
            else
                return false; //No match and no star occured yet to consume the problem
        }
        while(j<n && p[j] == '*')
            j++;
        return j==n;
    }
};