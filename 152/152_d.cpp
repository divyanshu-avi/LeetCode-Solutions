class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, n = nums.size(), ans, maxi, mini, big, small;
        ans = maxi = mini = nums[0];
        for(i=1;i<n;i++)
        {
            
            big = maxi*nums[i];
            small = mini*nums[i];
            maxi = max({nums[i], big, small});
            mini =  min({nums[i], big, small});
            ans = max(ans, maxi);
        }
        return ans;
    }
};