class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1, pos = m+n-1;
        while(j>=0)
        {
            if(i<0 || nums2[j] >= nums1[i])
                nums1[pos--] = nums2[j--];
            else
                nums1[pos--] = nums1[i--];
        }
    }
};