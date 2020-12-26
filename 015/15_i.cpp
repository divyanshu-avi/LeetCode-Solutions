class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp{0,0,0};
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1,k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(j<k){
                if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
                else{
                    if(j>i+1 && nums[j]==nums[j-1]){
                        j++;
                        continue;
                    }
                    temp[0]=nums[i];
                    temp[1]=nums[j];
                    temp[2]=nums[k];
                    ans.push_back(temp);
                    j++;
                }
            }
        }
        return ans;
    }
};
