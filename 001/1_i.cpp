class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp, val;
        temp=nums;
        sort(temp.begin(),temp.end());
        int j=nums.size()-1, i=0;
        while(1){
            if(temp[i]+temp[j]>target){
                j--;
            }
            else if(temp[i]+temp[j]<target){
                i++;
            }
            else{
                val.push_back(temp[i]);
                val.push_back(temp[j]);
                break;
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val[0] || nums[i]==val[1]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
