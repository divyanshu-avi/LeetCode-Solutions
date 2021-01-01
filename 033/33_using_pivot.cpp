class Solution {
public:
    
    int search(vector<int>& nums, int target) {
       
        int n = nums.size();
        int l = 0;
        int r = n-1;
        int pivot;
        int mid;
        
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]== target)
                return mid;
            if(nums[mid]>nums[n-1]){
                l = mid+1;
                cout<<nums[mid]<<endl;
                
            }else{
                pivot = mid;
                r =  mid-1;
            }            
        }
        
        int largest;
        
        if(pivot == 0){
            l = 0; r = n-1;
            cout<<"pivot == 0";
        }
        else{
            if(nums[0]>target){
                l = pivot;
                r = n-1;
                cout<<l<<" "<<r;
            }else{
                l = 0;
                r = pivot-1;
                cout<<l<<" "<<r;
            }
    
        }
        
        
        while(l<=r){
            
            mid = l+ (r-l)/2;
            if(nums[mid]== target)
                return mid;
            else if(nums[mid]>target)
                r = mid-1;
            else 
                l = mid +1;
    
        }
        
        
        
        return -1;
        
        
    }
};
