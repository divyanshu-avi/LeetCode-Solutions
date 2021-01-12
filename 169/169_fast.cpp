class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1)
            return nums[0];
        
        int maxnum = nums[0];
        int counter = 0;
        
        for(int i =0 ; i<n ; i++){
            
            if(counter!=0){
                if(nums[i]!=maxnum)
                    counter--;
                else 
                    counter++;                
                
            }else{
                maxnum = nums[i];
                counter=1;
            }
            
        }
            
        
        return maxnum;
        
    }
};