class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        //If n = 1 or -1 the recursive call will return 0 so there won't be a problem.
        if(n>0)
            return n%2==0 ? myPow(x*x, n/2) : myPow(x*x, n/2)*x;
        else
            return n%2==0 ? myPow(1/(x*x), abs(n/2)) : myPow(1/(x*x), abs(n/2))*1/x;
    }
};