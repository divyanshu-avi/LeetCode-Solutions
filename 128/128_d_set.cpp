class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int i, j, n = nums.size(), ans = 0;
        unordered_set<int> set;
        for(i=0;i<n;i++)
            set.insert(nums[i]);
        
        for(i=0;i<n;i++)
            if(set.find(nums[i]-1) == set.end())//this means current element is the starting element of its sequence
            {
                for(j = nums[i]+1 ; set.find(j) != set.end(); j++);
                ans = max(ans, j-nums[i]);
            }
        return ans;
            
    }
};