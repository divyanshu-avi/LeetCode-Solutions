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
            if(m<l)//if earlier m==l then l can go ahead of m. So correct that.
                m=l;
            else if(nums[m] == 0)
                swap(nums[l++], nums[m]);//Don't do m++ here as current element at m (after swapping) hasn't been handled.
            else if(nums[m] == 2)
                swap(nums[m], nums[r--]);//Dont do m++ sam reason^^.
            else
                m++;
        }
    }
};