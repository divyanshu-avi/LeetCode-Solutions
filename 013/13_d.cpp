class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, i;
        for(i=0;i<s.length();i++)
        {
            if(i+1<s.length()&&val(s[i])<val(s[i+1]))
                ans -= val(s[i]);
            else
                ans += val(s[i]);
        }
        return ans;
    }
    int val(char a)
    {
        switch(a)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
};