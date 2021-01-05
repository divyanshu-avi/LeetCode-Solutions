class Solution {
public:
    
    int numDecodings(string s) {
        int n = s.length(), sum, i, next, cur, prev;
        
        prev = 1;
        cur = s[n-1]=='0' ? 0 : 1;
        for(i=n-2; i>=0;i--)
        {
            next = 0;
            if(s[i]!='0')
            {
                next += cur;
                sum = (s[i]-'0')*10 + (s[i+1]-'0');
                if(sum<=26)
                     next += prev;
            }
            //If 2 simultaneous answers are 0 that means one of them is 0 and we can't decode it.
            if(next==0 && cur==0)
                return 0;
            prev = cur;
            cur = next;
        }
        return cur;
    }
};