class Solution {
public:
    void recursion(vector<int>& nums, vector<int> temp, vector<vector<int>>& ans)
    {
        if(temp.size() == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(find(temp.cbegin(), temp.cend(), nums[i]) == temp.cend())
            {
                temp.push_back(nums[i]);
                recursion(nums, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recursion(nums, vector<int>(), ans);
        return ans;
    }
};