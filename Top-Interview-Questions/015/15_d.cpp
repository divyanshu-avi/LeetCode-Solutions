class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return vector<vector<int>>();
        int i, j, k, sum;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            j=i+1;k=nums.size()-1;
            while(j<k)
            {
                sum = nums[i]+nums[j]+nums[k];
                if(sum < 0)
                    j++;                    
                else if(sum>0)
                    k--;                
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    do
                        j++;
                    while(j<k && nums[j] == nums[j-1]);
                    do
                        k--;
                    while(j<k && nums[k] == nums[k+1]);
                }
                //cout<<i<<' '<<j<<' '<<k<<' '<<'|'<<' ';
            }
        }
        return ans;
    }
};