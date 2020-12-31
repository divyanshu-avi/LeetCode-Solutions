class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)
            return dividend;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int ans = 0, x, i, sign = (dividend>=0)==(divisor>=0);
        long long int a, b;
        a = abs(dividend);
        b = abs(divisor);
        for(i=31;i>=0;i--)
        {
            if(b<<i <= a)
            {
                a -= b<<i;
                ans += 1<<i;
            }
        }
        return sign?ans:-ans;
    }
};