class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        int start=1, end=x, mid;
        while(start < end)
        {
            mid = start + (end-start+1)/2;//Overflow possible here
            if( mid>= 46341 || mid*mid > x )//46341 is the overflow limit for mid*mid
                end = mid-1;
            else if(mid*mid < x)
                start = mid;
            else
                return mid;
        };
        return start;
    }
};