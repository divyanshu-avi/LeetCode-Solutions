class Solution {
public:
    int titleToNumber(string s) {
        char c;
        int i, n = s.length(), base=1, ans=0;
        for(i=n-1;i>=0;i--)
        {
            if(i!=n-1) base*=26;
            ans += base*(s[i] - 'A' + 1);
        }
        return ans;
    }
};