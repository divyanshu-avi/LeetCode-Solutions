class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(!nums.size())
            return 0;
        int i, ans = nums[0], cur_max = nums[0];
        for(i=1;i<nums.size();i++)
        {
            cur_max = max(nums[i], nums[i] + cur_max);
            //cur_max is the max sum obtainable using elements till current index and including current index.
            ans = max(ans, cur_max);
        }
        return ans;
    }
};