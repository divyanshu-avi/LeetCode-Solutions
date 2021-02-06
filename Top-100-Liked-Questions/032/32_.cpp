class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0, reach=0, steps=0;
        for(int i=0;i<nums.size()-1;i++){
            reach=max(reach, i+nums[i]);
            if(curr>=nums.size()-1) break;
            if(curr==i){
                steps++;
                curr=reach;
            }
        }
        return steps;
    }
};
