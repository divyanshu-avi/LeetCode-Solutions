class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> mem(n,-1);
        return dp(mem,nums,0);
        
    }
    
    int dp(vector<int>& mem, vector<int>& nums, int i){
        
        if(i >=nums.size())
            return 0;
        
        if(mem[i]!= -1)
            return mem[i];
        
        
        int r = nums[i] + dp(mem,nums,i+2);
        int nr = dp(mem,nums,i+1);
        
        return mem[i] = max(r,nr);
        
        
        
        
    }
    
};