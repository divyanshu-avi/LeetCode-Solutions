class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i =0; i<n; i++){
            mp[nums[i]]++;  
            
        }
        
        int ans = 0;
        
        for(auto i : mp){
            
            if(mp.find(i.first-1)==mp.end()){
                int curr = 1;
                while(mp.find(i.first+curr)!=mp.end())
                    curr++;
                ans = max(ans,curr);
            }
            
        }
        return ans;
    
        
        
        
    }
};