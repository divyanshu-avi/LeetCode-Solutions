class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start, end, mid, n, ansl, ansr;
        n = nums.size();
        if(!n)
            return {-1,-1};
        start=0; end = n-1;
        while(start!=end)
        {
            mid = start + (end-start)/2; //prevents overflows
            //Not really needed here as n<=10^5 but a good practice nevertheless.
            if(nums[mid] >= target)
                end = mid;
            else
                start = mid+1;
        }
        if(nums[start]==target)
            ansl = start;
        else
            return {-1,-1};
        end = n-1;
        while(start!=end)
        {
            mid = start + (end-start+1)/2;
            //Here instead of floor I want ceiling that's why a +1.
            if(nums[mid] <= target)
                start = mid;
            else
                end = mid-1;
        }
        ansr = start;
        return {ansl,ansr};
    }
};