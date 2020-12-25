class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxvol=0;
        while(i<j){
            int vol=(j-i)*min(height[i], height[j]);
            maxvol=max(maxvol, vol);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxvol;
    }
};
