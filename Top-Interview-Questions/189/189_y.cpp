class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k=k%nums.size();
        if(k==0)
            return;
			
        k=nums.size()-k;
       reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        reverse(nums.begin(),nums.end());
            
   
    }
};