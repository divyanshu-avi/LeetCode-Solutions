class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        while(j<nums.size())
        {
            if(nums[j]==nums[i])
                j++;
            else
                nums[++i]=nums[j++];
        }
        return nums.size()>0?i+1:0;
    }
};