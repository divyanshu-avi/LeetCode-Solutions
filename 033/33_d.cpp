class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), start, end, mid;
        start=0; end=n-1;
        while(start<=end)
        {
            mid = start + (end-start)/2;//prevents overflow
            if(nums[mid] == target)
                return mid;
            else
            {
                if(nums[mid]<target)
                {
                    if(nums[mid]>nums[start] || start==mid)//start to mid is sorted
                        start = mid+1;
                    else//mid to end is sorted
                    {
                        if(nums[end]<target)
                            end = mid-1;
                        else
                            start = mid+1;
                    }
                }
                else//nums[mid]>nums[target]
                {
                    if(nums[mid]>nums[start] || start==mid)//start to mid is sorted
                    {
                        if(nums[start] > target)
                            start = mid+1;
                        else
                            end = mid-1;
                    }
                    else//mid to end is sorted
                        end = mid-1;
                }
            }
        }
        return -1;
    }
};