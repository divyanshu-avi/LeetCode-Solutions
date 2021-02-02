class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zero=0,two=0;
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            
            if(nums[i]==0){
                if(i>zero){    
                   nums[i]=nums[0+zero];
                    nums[0+zero]=0;
                    i--;
                }
                zero++;                
                
            }else if(nums[i]==2){
                if(i<n-1-two){
                    nums[i]=nums[n-1-two];
                    nums[n-1-two]=2;
                    i--;
                }
                two++;
            }
        }       
        return;
    }
};