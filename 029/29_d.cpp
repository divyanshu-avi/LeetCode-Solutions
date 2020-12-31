class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)
            return dividend;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int ans = 0, x, sign = (dividend>=0)==(divisor>=0);
        long long int a, b;
        a = abs(dividend);
        b = abs(divisor);
        while(a-b >= 0)
        {
            x=0;
            while(a - (b<<1<<x) >=0)
                x++;
            ans += 1<<x;
            a -= b<<x;
        }
        return sign?ans:-ans;
    }
};