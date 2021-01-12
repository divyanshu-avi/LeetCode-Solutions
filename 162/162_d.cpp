class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l, r, m, n = nums.size();
        l=0 ; r = n-1;
        while(l<=r)
        {
            m = l + (r-l)/2;
            if( (m==0 || nums[m]>nums[m-1]) && (m==n-1 || nums[m]>nums[m+1]) )
                break;
            /*Doing the m+1 case first is important. While taking mid we are using floor so, 
            when n=2 and m = 0, m-1 maynot be valid but m+1 will always be valid (because floor)*/
            else if(nums[m+1] > nums[m])
                l = m+1;
            else
                r = m-1;
        }
        return m;
    }
};