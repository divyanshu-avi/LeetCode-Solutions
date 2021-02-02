class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()<=1)
            return;
        int l, m, r;
        l=0; m=0;
        r=nums.size()-1;
        while(m<=r)
        {
            if(nums[m] == 0 && m>l)//m>l ensures we aren't doing useless swaps and some times l can go ahead of m so it also handles that.
                swap(nums[l++], nums[m]);//Don't do m++ here as current element at m (after swapping) hasn't been handled.
            else if(nums[m] == 2)
                swap(nums[m], nums[r--]);//Dont do m++ sam reason^^.
            else
                m++;
        }
    }
};
