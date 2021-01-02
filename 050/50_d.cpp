class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1 || x == 1)
            return x;
        if(n == 0)
            return 1;
        if(n == -1)
            return 1/x;
        if(n>0)
            return n%2==0 ? myPow(x*x, n/2) : myPow(x*x, n/2)*x;
        else
            return n%2==0 ? myPow(1/(x*x), abs(n/2)) : myPow(1/(x*x), abs(n/2))*1/x;
    }
};