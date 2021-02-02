class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        unordered_map<int, int> past;
        for(i=0;i<nums.size();i++)
        {
            int diff = target - nums[i];
            if(past.find(diff)!=past.end())
                return {past[diff], i};
            past[nums[i]] = i;
        }
        
        return vector<int>();//empty vector
    }
};