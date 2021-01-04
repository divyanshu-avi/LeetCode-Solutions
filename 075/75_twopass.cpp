class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero=0,one=0,two=0;
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            nums[i]==0?zero++:nums[i]==1?one++:two++;   
        }
        
        int i=0;
        while(i<n){
            while(zero--){
                nums[i]=0;
                i++;
            }
            while(one--){
                nums[i]=1;
                i++;
            }
            while(two--){
                nums[i]=2;
                i++;
            }
        }
        
        return;
    }
};