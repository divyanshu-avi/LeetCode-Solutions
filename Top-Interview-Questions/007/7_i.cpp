class Solution {
public:
    int reverse(int x) {
        int ans=0, flag=0;
        if(x==INT_MIN){
            return 0;
        }
        if(x<0){
            flag=1;
            x=abs(x);
        }
        int rem;
        while(x!=0){
            if(INT_MAX/10<ans){
                return 0;
            }
            ans*=10;
            rem=x%10;
            x/=10;
            ans+=rem;
        }
        if(flag==1){
            ans*=-1;
        }
        return ans;
    }
};
