class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, max_reach = 0;
        for(i=0;i<nums.size() && i<=max_reach;i++)//2nd condition makes sure that current elment is reachable.
            max_reach = max(max_reach, i+nums[i]);
        return max_reach >= nums.size()-1;
        //
    }
};