class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end())
                st.insert(nums[i]);
            else return 1;
        }
        return 0;
    }
};
