class Solution {
public:
    vector<int> arr;
    void place(int val)
    {
        if (val <= arr[0])
            arr[0] = val;
        else if (val <= arr[1])
            arr[1] = val;
        else
            arr[2] = val;
    }

    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), i, j = 0;
        if (n < 3)
            return false;
        arr.resize(3);
        arr[0] = nums[0];
        for (i = 1; i < n && j != 2; i++)
        {
            if (nums[i] > arr[j])
                arr[++j] = nums[i];
            else
                place(nums[i]);
        }
        /*for(i=0;i<3;i++)
            cout<<arr[i]<<' ';*/
        return j == 2;
    }
};