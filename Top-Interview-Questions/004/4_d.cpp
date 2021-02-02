class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int sum, lx, ly, rx, ry, px, py, start, end;
        sum = nums1.size() + nums2.size();
        start = 0; end = nums1.size();
        while(start<=end)
        {
            px = (start+end)/2;
            py = (sum+1)/2 - px;
            lx = (px==0)? INT_MIN : nums1[px-1];
            rx = (px==nums1.size())? INT_MAX : nums1[px];
            ly = (py==0)? INT_MIN : nums2[py-1];
            ry = (py==nums2.size())? INT_MAX : nums2[py];
            if(lx>ry)//Need to move left in nums1 and right in nums2
                end = px-1;
            else if(ly>rx)//Need to move right in nums1 and left in nums2
                start = px+1;
            else
                return (sum%2!=0)? max(lx,ly) : (double)(max(lx,ly) + min(rx, ry))/2;
        }
        return -1;
    }
};