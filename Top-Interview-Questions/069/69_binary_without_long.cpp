class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        if(x==1)
            return 1;
        int l=1, r=x;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x/mid<mid){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l-1;
    }
};
