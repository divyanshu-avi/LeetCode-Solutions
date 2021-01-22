class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(-1);
        int temp;
        
        for(int i =0; i<n; i++){
            
            if(nums[i]==-1)
                continue;
            int j = nums[i];
            
            while(nums[j]!= -1){
                temp = j;
                j = nums[j];
                nums[temp] = -1;    
            }    
        }
        
        for(int i =0; i<n; i++){
            if(nums[i]!= -1)
                return i;
        }
        
        return n;
    }
};