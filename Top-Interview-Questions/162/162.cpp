class Solution {
public:
    int findPeakElement(vector<int>& nums) {
     
        int n = nums.size();
        
        if(n == 1)
            return 0;
        if(n==2)
            return nums[0]>nums[1]?0:1;
        
        int l = 0, r = n-1;
        int mid;
        
        while(l<r){
            
            mid = l + (r-l)/2;
        
            if(nums[mid]>nums[mid+1]){
                r=mid;
            }else{
               l=mid+1;
            }
            
        }
         
        return l;
        
    }
};