class Solution {
public:
    int reverse(int x) {
        long long int ans = 0;
        int sign = 1, rem;
        if(x<0)
            sign = -1;
        x = abs(x);
        while(x)
        {
            rem = x%10;
            x = x/10;
            ans = ans*10 + rem;
        }
        ans = ans*sign;
        if(ans<INT_MIN || ans>INT_MAX)
            return 0;
        return ans;
    }
};