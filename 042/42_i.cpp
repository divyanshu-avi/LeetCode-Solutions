class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1, water=0;
        int left_max=0, right_max=0;
        while(left<right){
            if(height[left]<height[right]){
                left_max=max(left_max, height[left]);
                water+=left_max-height[left];
                left++;
            }
            else{
                right_max=max(right_max, height[right]);
                water+=right_max-height[right];
                right--;
            }
        }
        return water;
    }
};
