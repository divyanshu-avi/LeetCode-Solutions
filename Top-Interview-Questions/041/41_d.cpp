class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), i=0;
        while(i<n)
        {
            if(nums[i] >=1 && nums[i] <=n && nums[i]!=i+1 && nums[i] != nums[nums[i]-1])//try to make value of ith element = i. If both are same then move on.
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for(i=0;i<n && nums[i] == i+1;i++);
        return i+1;
        
    }
};