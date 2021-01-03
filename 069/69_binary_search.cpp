class Solution {
public:
    int mySqrt(int x) {
    
        if(x == 0)
            return 0;
        
        int l = 1, r = x;
        long long int mid;
        int ans=1;
        
        while(l<=r){
            
            mid = l + (r-l)/2;
            if((mid*mid)==x){
                return mid;
                cout<<"broke here";}
            else if((mid*mid)>x){
                r = mid-1;
            }
            else{
                l = mid+1;
                ans = mid;
            }
            
        }
        
        return ans;
        
    }
};