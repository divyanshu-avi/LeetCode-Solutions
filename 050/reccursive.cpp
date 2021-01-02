class Solution {
public:
    double myPow(double x, int n) {
     
        if(n == 1)
            return x;
        if(n==0)
            return 1.0;
        
        if(n == INT_MIN)
            return pow(x*x,n/2);
            
        if(n<0)
            return pow(1/x,-n);
       
        double result = myPow(x*x,n/2);
        
        if(n%2)
            result = result *x;
        
        return result;
        
    }
};
