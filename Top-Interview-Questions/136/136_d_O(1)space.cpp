class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i, n = nums.size(), ans=nums[0];
        for(i=1;i<n;i++)
            ans = ans^nums[i];
        return ans;
;    }
};