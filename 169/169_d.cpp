class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i, n = nums.size(), ans = nums[0], count = 1;
        for(i=1;i<n;i++)
        {
            if(nums[i] == ans)
                count++;
            else
                count--;
            if(!count)
            {
                count = 1;
                ans = nums[i];
            }
        }
        return ans;
    }
};