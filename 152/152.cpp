class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];
        
        for(int i =1; i<nums.size();i++){
            cout<<ans<<" "<<maxi<<" "<<mini<<endl;
            
            int m = maxi;         
            int mi = mini;
            maxi = max(nums[i], max(m*nums[i],mi*nums[i] ));
            mini = min(nums[i], min(m*nums[i],mi*nums[i] ));
            ans = max(maxi,ans);
            
        }
        
        return ans;
        
    }
};