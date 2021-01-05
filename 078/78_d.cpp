class Solution {
public:
    //Uncomment the commented part (excluding this one of course!) to deal with duplicate elements in the input array.
    void generate(vector<int>& nums, int pos, vector<int> &temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);
        if(pos==nums.size())
            return;
        for(int i=pos;i<nums.size();i++)
        {
            //if(i==nums.size()-1 || nums[i]!=nums[i+1])
            //{
                temp.push_back(nums[i]);
                generate(nums, i+1, temp, ans);
                temp.pop_back();
            //}
        }
    }
    //
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(!nums.size())
            return ans;
        //sort(nums.begin(), nums.end());
        generate(nums, 0, temp, ans);
        return ans;
    }
};